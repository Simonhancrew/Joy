impl Solution {
  pub fn valid_ip_address(query_ip: String) -> String {
    if query_ip.contains('.') && query_ip.contains(':') {
      return String::from("Neither");
    }

    let mut split = |tar: &str| -> Vec<&str> {
      let mut rec = Vec::new();
      let (mut i, n) = (0, query_ip.len());
      while i < n {
        let mut j = i;
        while j < n && &query_ip[j..j + 1] != tar {
          j += 1
        }
        rec.push(&query_ip[i..j]);
        if j == n - 1 {
          rec.push("");
        }
        i = j + 1
      }
      rec
    };
    // 生命周期我草泥马
    let check4 = || -> String {
      let rec = split(".");
      if rec.len() != 4 {
        return String::from("Neither");
      }
      for s in &rec {
        if s.len() > 3 || s.is_empty() {
          return String::from("Neither");
        }
        if s.len() > 1 && &s[0..1] == "0" {
          return String::from("Neither");
        }
        for t in s.as_bytes() {
          if t < &b'0' || t > &b'9' {
            return String::from("Neither");
          }
        }
        let num: usize = s.parse().unwrap();
        if num > 255 {
          return String::from("Neither");
        }
      }
      String::from("IPv4")
    };

    let check6 = || -> String {
      let rec = split(":");
      if rec.len() != 8 {
        return String::from("Neither");
      }
      let check = |u| -> bool {
        if u >= b'0' && u <= b'9' {
          return true;
        }
        if u >= b'a' && u <= b'f' {
          return true;
        }
        if u >= b'A' && u <= b'F' {
          return true;
        }
        false
      };

      for s in rec {
        if s.is_empty() || s.len() > 4 {
          return String::from("Neither");
        }
        for &t in s.as_bytes() {
          if !check(t) {
            return String::from("Neither");
          }
        }
      }

      String::from("IPv6")
    };

    if query_ip.contains('.') {
      return check4();
    }
    if query_ip.contains(':') {
      return check6();
    }
    String::from("Neither")
  }
}
