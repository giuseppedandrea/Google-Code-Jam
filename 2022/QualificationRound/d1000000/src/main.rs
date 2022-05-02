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
    let n = parse_num::<u32>();
    for case in 1..=n {
        print!("Case #{}: ", case);

        let n = parse_num::<usize>();
        let mut sides = parse_vec::<usize>();
        sides.sort();

        let mut count: usize = 0;
        for i in 0..n {
            if sides[i] > count {
                count += 1;
            }
        }

        println!("{}", count);
    }
}
