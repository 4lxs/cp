fn sieve(arr: &mut Vec<i64>) {
    let mut isprime = vec![true; 10000];
    for i in 2..10000 {
        if !isprime[i] {
            continue;
        }
        arr.push(i as i64);
        for j in (2 * i..10000).step_by(i) {
            isprime[j] = false
        }
    }
}

fn main() {
    let mut primes = Vec::with_capacity(1000);
    sieve(&mut primes);
    let n = 20;
    let mut divs: Vec<i64> = vec![];

    for i in 1..=n {
        let mut i = i;
        for div in &divs {
            if i == 1 {
                break;
            }
            if i % div == 0 {
                i /= div;
            }
        }
        for prime in &primes {
            if i == 1 {
                break;
            }
            while i % prime == 0 {
                divs.push(*prime);
                i /= prime;
            }
        }
    }
    let ans = divs.iter().product::<i64>();
    println!("{}", ans);
}
