use std::fs::File;
use std::io::{self, Read};
   
fn find_largest_index(nets: &Vec<f64>) {
    let index_of_max: Option<usize> = nets
        .iter()
        .enumerate()
        .max_by(|(_, a), (_, b)| a.total_cmp(b))
        .map(|(index, _)| index);
    println!("{:?}",index_of_max);
}

fn main() -> io::Result<()> {
    let mut file = File::open("./nums.txt")?;
    let mut contents = String::new();
    
    file.read_to_string(&mut contents)?;
  
    let mut nums = Vec::new(); 
    for line in contents.lines(){
        let numbers: Vec<&str> = line
                .split(",")
                .collect();
        
        let base_as_str = numbers[0].to_string();
        let base = base_as_str.parse::<i64>().unwrap() as f64;
                                                 
        let exp_as_str = numbers[1].to_string();
        let exp = exp_as_str.parse::<i64>().unwrap() as f64;

        let reduced_number = exp * base.ln();
        nums.push(reduced_number);
    }
    find_largest_index(&nums);
    Ok(())
}
//Output: Some(708)
