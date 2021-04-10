// In an alien language, surprisingly they also use english lowercase letters, but possibly 
// in a different order. The order of the alphabet is some permutation of lowercase letters.
// Given a sequence of words written in the alien language, and the order of the alphabet, 
// return true if and only if the given words are sorted lexicographicaly in this alien language.

class Solution {
    boolean isBigger(String word1, String word2, int[] hash){
        int len = word1.length() > word2.length() ? word2.length() : word1.length();
        
        for(int i = 0; i < len; i++){
            if(word1.charAt(i) != word2.charAt(i)){
                return hash[word1.charAt(i) - 'a'] > hash[word2.charAt(i) - 'a'];
            }
        }
        
        return word1.length() > word2.length();
    }
    
    public boolean isAlienSorted(String[] words, String order) {
        
        int[] hash = new int[26];
        
        for(int i = 0; i < 26; i++){
            hash[order.charAt(i) - 'a'] = i;
        }
        
        for(int i = 1; i < words.length; i++) {
            if(isBigger(words[i-1], words[i], hash)){
                return false;
            }
        }
        
        return true;        
    }
}