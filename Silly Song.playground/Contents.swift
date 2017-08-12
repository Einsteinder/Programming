//: Playground - noun: a place where people can play

import UIKit

var str = "Hello, playground"
let vowelList = ["a", "e", "i", "o", "u"]
vowelList.contains("a")


func shortNameFromName(fullName: String) -> String {
    let vowelList = ["a", "e", "i", "o", "u"]
    if let fistLetter = fullName.characters.first{
        if (vowelList.contains(String(fistLetter).lowercaseString)){
            return fullName
        }else{
        }
    }
    return fullName.substringFromIndex(str.startIndex.successor())

}






func shortNameForName(name: String) -> String {
    let lowercaseName = name.lowercaseString
    let vowelSet = NSCharacterSet(charactersInString: "aeiouAEIOU")

    if let firstVowelRange = name.rangeOfCharacterFromSet(vowelSet, options: .CaseInsensitiveSearch) {
        return lowercaseName.substringFromIndex(firstVowelRange.startIndex)
    }
    
    // No vowels - return the full name
    return lowercaseName
}
let bananaFanaTemplate = [
    "<FULL_NAME>, <FULL_NAME>, Bo B<SHORT_NAME>",
    "Banana Fana Fo F<SHORT_NAME>",
    "Me My Mo M<SHORT_NAME>",
    "<FULL_NAME>"].joinWithSeparator("\n")

func lyricsForName(lyricsTemplate: String, fullName: String) -> String {
    let shortName = shortNameForName(fullName)
    
    let lyrics = lyricsTemplate
        .stringByReplacingOccurrencesOfString("<FULL_NAME>", withString: fullName)
        .stringByReplacingOccurrencesOfString("<SHORT_NAME>", withString: shortName)
    
    return lyrics
}
lyricsForName(bananaFanaTemplate, fullName: "nate")
shortNameForName("OaaAAate")
// Shows 'ate'
shortNameForName("Zroöe")
// Shows 'alia'
shortNameFromName("oaaAAate")