#through the concepts of OOPs
#created a school library project in javascript

class Media{
   constructor(title){
     this._title = title;
     this._isCheckedOut = false;
     this._ratings = [];
  }
  get title(){
    return this._title;
  }
  get isCheckedOut(){
    return this._isCheckedOut;
  }
  get ratings(){
    return this._ratings;
  }
  set isCheckedOut(check){
   return this._isCheckedOut = check;
  }
  toggleCheckOutStatus(){
     this._isCheckedOut = !this._isCheckedOut;
    /*if(this._isCheckedOut == false){
      return this._isCheckedOut = true;
    }else{
      return this._isCheckedOut = false;
    }*/
  }
  getAverageRating(){
    let sum = this._ratings.reduce((sum1,sum2) => sum1 + sum2,0);
    const result = sum/(this._ratings.length);
    return sum;
  }
  addRating(add){
    this._ratings.push(add);
  }
};
class Book extends Media{
  constructor(author,pages,title){
  super(title);
  /*super(isCheckedOut);
  super(ratings);*/
  this._author = author;
  this._pages = pages;
  }
  get author(){
    return this._author;
  }
  get pages(){
    return this._pages;
  }
};
class Movie extends Media{
  constructor(director,runTime,title){
    super(title);
    /*super(isCheckedOut);
    super(ratings);*/
    this._director = director;
    this._runTime = runTime;
  }
  get director(){
    return this._director;
  }
  get runTime(){
    return this._runTime;
  }
};
class CD extends Media{
  constructor(artist,title,songs){
    super(title);
    this._artist = artist;
    this._songs = songs;
  }
  get artist(){
    return this._artist;
  }
  get songs(){
    return this._songs;
  }
  shuffle(){
    let len = this._songs.length,index,temp;
    while(len > 0){
      index = Math.floor(Math.random()*len);
      len--;
      temp= this._songs[len];
      this._songs[len] = this._songs[index];
      this._songs[index] = temp;
    }
    return this._songs;
  }
  };
const historyOfEverything = new Book('Bill Bryson',544,'A Short History of Nearly Everything')
historyOfEverything.toggleCheckOutStatus();
console.log(historyOfEverything.isCheckedOut);
historyOfEverything.addRating(4);
historyOfEverything.addRating(5);
historyOfEverything.addRating(5);
console.log(historyOfEverything.getAverageRating());
const speed = new Movie('Jan de Bont',116,'speed');
speed.toggleCheckOutStatus();
console.log(speed.isCheckedOut);
speed.addRating(1)
speed.addRating(1)
speed.addRating(5)
console.log(speed.getAverageRating());
