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
    let n = parse_num::<usize>();
    for case in 1..=n {
        print!("Case #{}: ", case);

        let mut printers = Vec::with_capacity(3);
        for _ in 0..3 {
            printers.push(parse_vec::<usize>());
        }

        let mut min_colors = Vec::with_capacity(4);
        for i in 0..4 {
            min_colors.push(min(min(printers[0][i], printers[1][i]), printers[2][i]));
        }

        let sum: usize = min_colors.iter().sum();
        if sum < 1_000_000 {
            println!("IMPOSSIBLE");
            continue;
        }

        let mut str_colors = Vec::with_capacity(4);
        let mut res = sum - 1_000_000;
        for i in 0..4 {
            if res > 0 {
                if res <= min_colors[i] {
                    str_colors.push((min_colors[i] - res).to_string());
                    res = 0;
                } else {
                    str_colors.push("0".to_string());
                    res -= min_colors[i];
                }
            } else {
                str_colors.push(min_colors[i].to_string());
            }
        }

        println!("{}", str_colors.join(" "));
    }
}
