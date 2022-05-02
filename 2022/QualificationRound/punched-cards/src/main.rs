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
    let n = parse_num::<usize>();
    for case in 1..=n {
        let line = parse_vec::<usize>();
        let r = line[0];
        let c = line[1];

        println!("Case #{}:", case);
        for i in 0..(2 * r + 1) {
            if i % 2 == 0 {
                if i == 0 {
                    print!("..");
                    print!("{}", "+-".repeat(c - 1));
                    println!("+");
                } else {
                    print!("{}", "+-".repeat(c));
                    println!("+");
                }
            } else {
                if i == 1 {
                    print!("..");
                    print!("{}", "|.".repeat(c - 1));
                    println!("|");
                } else {
                    print!("{}", "|.".repeat(c));
                    println!("|");
                }
            }
        }
    }
}
