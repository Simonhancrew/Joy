impl Solution {
  pub fn min_number_of_hours(
    initial_energy: i32,
    initial_experience: i32,
    energy: Vec<i32>,
    experience: Vec<i32>,
  ) -> i32 {
    let n = energy.len();
    let (mut s1, mut s2, mut mx) = (0, 0, experience[0]);
    for i in 0..n {
      s1 += energy[i];
      s2 += experience[i];
      if i > 0 {
        mx = mx.max(experience[i] - s2 + experience[i]);
      }
    }
    let mut res = 0;
    if initial_energy <= s1 {
      res += s1 - initial_energy + 1;
    }
    if initial_experience <= mx {
      res += mx - initial_experience + 1;
    }
    res
  }
}
