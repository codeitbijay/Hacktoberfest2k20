function count_change(coins, numDenom, value) {
  // dp table
  const tbl = new Array(value + 1).fill(0);
  tbl[0] = 1; // base case where value=0

  // build the table from bottom up,
  // progressively using more coins
  for (let i = 0; i < numDenom; i++) {
    for (let j = coins[i]; j <= value; j++) {
      tbl[j] += tbl[j - coins[i]];
    }
  }

  return tbl[value];
}
