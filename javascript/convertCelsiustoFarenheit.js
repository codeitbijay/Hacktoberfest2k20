function convertToF(celsius) {
  var fahrenheit = celsius * (9 / 5) + 32;
  if (typeof fahrenheit !== "undefined") {
    return fahrenheit;
  } else {
    return "fahrenheit not defined";
  }
}


// Change the inputs below to test your code
convertToF(30);
