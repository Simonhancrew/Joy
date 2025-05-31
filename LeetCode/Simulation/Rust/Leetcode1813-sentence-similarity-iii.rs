use std::cmp::min;

impl Solution {
  pub fn are_sentences_similar(sentence1: String, sentence2: String) -> bool {
    let mut s1 = sentence1.split(' ').collect::<Vec<&str>>();
    let mut s2 = sentence2.split(' ').collect::<Vec<&str>>();
    let len1 = s1.len();
    let len2 = s2.len();

    let mut i = 0;
    while i < len1 && i < len2 && s1[i] == s2[i] {
      i += 1;
    }

    let mut j = 0;
    while j < len1 - i && j < len2 - i && s1[len1 - j - 1] == s2[len2 - j - 1] {
      j += 1;
    }

    i + j == min(len1, len2)
  }
}
