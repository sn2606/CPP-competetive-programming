# Design a special dictionary which has some words and allows you to search the words in it by a prefix and a suffix.
# Implement the WordFilter class:
# WordFilter(string[] words) Initializes the object with the words in the dictionary.
# f(string prefix, string suffix) Returns the index of the word in the dictionary which has the prefix prefix
#  and the suffix suffix. If there is more than one valid index, return the largest of them. 
#  If there is no such word in the dictionary, return -1.

class WordFilter:
    
    def __init__(self, words: List[str]):
        from collections import defaultdict
        self.prefixes = defaultdict(set)
        self.suffixes = defaultdict(set)
        self.weights = {}
        for ind, word in enumerate(words):
            prefix = ''
            suffix = ''
            l = [''] + list(word)
            r = [''] + list(word[::-1])
            for char in l:
                prefix += char
                self.prefixes[prefix].add(word)
            for char in r:
                suffix += char
                self.suffixes[suffix[::-1]].add(word)
            self.weights[word] = ind        
        

    def f(self, prefix: str, suffix: str) -> int:
        weight = -1;
        for word in self.prefixes[prefix] & self.suffixes[suffix]:
            if self.weights[word] > weight:
                weight = self.weights[word]                
        return weight
        


# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(prefix,suffix)