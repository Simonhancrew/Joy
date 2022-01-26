impl Solution {
    pub fn detect_capital_use(word: String) -> bool {
        // 全为大写 或 除了首字母全为小写
        word.chars().all(|ch| ch.is_ascii_uppercase()) || word.chars().skip(1).all(|ch| ch.is_ascii_lowercase())
    }
}