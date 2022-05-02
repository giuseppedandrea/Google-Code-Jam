use std::cmp::min;
use std::io;
use std::str;

fn input_line() -> String {
    let mut input = String::new();
    match io::stdin().read_line(&mut input) {
        Ok(_) => input,
        Err(e) => panic!("error: {}", e),
    }
}

fn parse_num<T: str::FromStr>() -> T {
    match input_line().trim().parse::<T>() {
        Ok(n) => n,
        Err(_) => panic!("error in parsing number"),
    }
}

fn parse_vec<T: str::FromStr>() -> Vec<T> {
    input_line().split_ascii_whitespace().map(|x| match x.parse::<T>() {
        Ok(n) => n,
        Err(_) => panic!("error in parsing vector"),
    }).collect()
}

fn main() {
    let t = parse_num::<u32>();
    for case in 1..=t {
        print!("Case #{}: ", case);

        let line = parse_vec::<usize>();
        let n = line[0];

        let mut min_p = Vec::with_capacity(n + 1);
        min_p.push(0);
        let mut max_p = Vec::with_capacity(n + 1);
        max_p.push(0);
        for _ in 0..n {
            let p = parse_vec::<u32>();
            min_p.push(*p.iter().min().unwrap());
            max_p.push(*p.iter().max().unwrap());
        }

        let mut dp= Vec::with_capacity(n + 1);
        dp.push((0u64, 0u64));
        for i in 1..=n {
            dp.push((
                ((max_p[i] - min_p[i]) as u64) + min(
                    dp[i - 1].0 + ((if max_p[i - 1] >= min_p[i] { max_p[i - 1] - min_p[i] } else { min_p[i] - max_p[i - 1] }) as u64),
                    dp[i - 1].1 + ((if min_p[i - 1] >= min_p[i] { min_p[i - 1] - min_p[i] } else { min_p[i] - min_p[i - 1] }) as u64)
                ),
                ((max_p[i] - min_p[i]) as u64) + min(
                    dp[i - 1].0 + ((if max_p[i - 1] >= max_p[i] { max_p[i - 1] - max_p[i] } else { max_p[i] - max_p[i - 1] }) as u64),
                    dp[i - 1].1 + ((if min_p[i - 1] >= max_p[i] { min_p[i - 1] - max_p[i] } else { max_p[i] - min_p[i - 1] }) as u64)
                )
            ));
        }

        println!("{}", min(dp[n].0, dp[n].1));
    }
}
