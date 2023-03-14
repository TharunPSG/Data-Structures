function generateCombinations(str) {
    var result = [];
  
    // Recursive helper function
    function helper(subStr, combo) {
      if (subStr.length === 0) {
        result.push(combo);
      } else {
        // Take the first character of subStr
        var first = subStr[0];
        // Get the rest of the characters
        var rest = subStr.slice(1);
        // Call helper function on rest of string with and without first character
        helper(rest, combo + first);
        helper(rest, combo);
      }
    }
  
    helper(str, '');
    return result;
  }