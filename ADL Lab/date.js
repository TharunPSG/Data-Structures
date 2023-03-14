function lastday(year, month) {
    return new Date(year, month + 1, 0).getDate();
  }
  
  document.write(lastday(2014, 0)); // Output: 31
  document.write(lastday(2014, 1)); // Output: 28
  document.write(lastday(2014, 11)); // Output: 31
  