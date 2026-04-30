# JSON Diagnostics Contract

**Produced by**: `gram check --json`  
**Schema version**: 1

---

## Top-level Object

```json
{
  "schema_version": 1,
  "tool": "gram/0.4.0",
  "files": [ <FileResult>, ... ]
}
```

| Field | Type | Description |
|-------|------|-------------|
| `schema_version` | integer | Always `1` — consumers should reject higher values they do not understand |
| `tool` | string | `"gram/<semver>"` — version of the gram binary that produced this output |
| `files` | array | One entry per checked file (may be empty if no files were checked) |

---

## FileResult

```json
{
  "path": "data/example.gram",
  "diagnostics": [ <Diagnostic>, ... ]
}
```

| Field | Type | Description |
|-------|------|-------------|
| `path` | string | File path exactly as passed to `gram check`; `-` for stdin |
| `diagnostics` | array | Zero or more diagnostics for this file |

---

## Diagnostic

```json
{
  "severity": "error",
  "message": "Unexpected token ';'",
  "range": {
    "start": { "line": 2, "character": 14 },
    "end":   { "line": 2, "character": 15 }
  }
}
```

| Field | Type | Description |
|-------|------|-------------|
| `severity` | string | One of `"error"`, `"warning"`, `"information"`, `"hint"` |
| `message` | string | Human-readable description of the issue |
| `range` | Range | Source location (0-based, UTF-16 character offsets) |

---

## Range

```json
{
  "start": { "line": 2, "character": 14 },
  "end":   { "line": 2, "character": 15 }
}
```

| Field | Type | Description |
|-------|------|-------------|
| `start` | Position | Start of the offending span (inclusive) |
| `end` | Position | End of the offending span (exclusive) |

---

## Position

```json
{ "line": 2, "character": 14 }
```

| Field | Type | Description |
|-------|------|-------------|
| `line` | integer | 0-based line number |
| `character` | integer | 0-based UTF-16 code-unit offset within the line |

---

## Exit Code Relationship

- Exit code 0 → all files had zero `"error"` severity diagnostics (warnings are allowed)
- Exit code 1 → at least one `"error"` severity diagnostic exists
- Exit code 2 → invocation error; JSON output may be absent or incomplete

---

## Complete Example

```json
{
  "schema_version": 1,
  "tool": "gram/0.4.0",
  "files": [
    {
      "path": "data/valid.gram",
      "diagnostics": []
    },
    {
      "path": "data/broken.gram",
      "diagnostics": [
        {
          "severity": "error",
          "message": "ERROR node in parse tree",
          "range": {
            "start": { "line": 0, "character": 5 },
            "end":   { "line": 0, "character": 6 }
          }
        }
      ]
    }
  ]
}
```
