extern crate rustc_serialize;

use rustc_serialize::hex::{FromHex};


fn main () {
	let hex_string = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
	println!("String is {} and {} long", hex_string, hex_string.len());

    let bytes_1 = hex_string.from_hex();
    let bytes = bytes_1.unwrap();


    println!("Bytes are (in decimal): {:?}", bytes);
    let result_str = String::from_utf8(bytes).unwrap();
    println!("This is the 'text' result? {}", result_str);

    // next, for each byte in the byte string, encode it as ascii?
    // what does base64 even mean?
    // so we got the ascii text and... then what?

    let x: u8 = 255 ;
	println!("Binary {:b}, int {}", x, x);

	let y: u8 = x << 2;

	println!("lsh 2 {:b}, int {}", y, y);

	let z: u8 = x & 0x3F;

	println!("lsh 2 {:b}, int {}", z, z);


 }

