const requestURL = "https://type.fit/api/quotes";

async function getQuotes(name) 
{
  let response = await fetch(requestURL);
  let data = await response.json();
  return data;
}

getQuotes().then(data => {
    let rand_num=Math.floor(Math.random() * 1500);
    let quotes_detail=data[rand_num];
    let text=quotes_detail['text'];
    let author=quotes_detail['author'];
    $("h2").append(text);
    $("p").append(author);
}); 
