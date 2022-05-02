use std::cmp::max;
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

        let _ = parse_num::<usize>();
        let mut d = parse_vec::<usize>();

        let mut max_d: usize = 0;
        let mut pay: usize = 0;
        while d.len() != 0 {
            if d.first().unwrap() <= d.last().unwrap() {
                if *d.first().unwrap() >= max_d { pay += 1 }
                max_d = max(max_d, d.remove(0));
            } else {
                if *d.last().unwrap() >= max_d { pay += 1 }
                max_d = max(max_d, d.remove(d.len() - 1));
            }
        }

        println!("{}", pay);
    }
}
