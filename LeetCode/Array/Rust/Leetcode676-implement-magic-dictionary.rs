struct MagicDictionary {
    rec: Vec<String>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MagicDictionary {
    fn new() -> Self {
        let rec = vec![];
        MagicDictionary { rec }
    }

    fn build_dict(&mut self, dictionary: Vec<String>) {
        self.rec = dictionary;
    }

    fn search(&self, search_word: String) -> bool {
        for pa in &self.rec {
            if pa.len() != search_word.len() {
                continue;
            }
            let (mut diff, n) = (0, search_word.len());
            let pa = pa.as_bytes();
            let s = &search_word.as_bytes();
            for i in 0..n {
                if pa[i] != s[i] {
                    diff += 1;
                }
                if diff > 1 {
                    break;
                }
            }
            if diff == 1 {
                return true;
            }
        }
        false
    }
}
