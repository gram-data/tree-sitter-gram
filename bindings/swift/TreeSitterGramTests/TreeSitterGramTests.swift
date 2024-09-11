import XCTest
import SwiftTreeSitter
import TreeSitterGram

final class TreeSitterGramTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_gram())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading Gram grammar")
    }
}
