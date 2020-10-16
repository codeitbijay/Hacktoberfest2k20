import React from 'react';
import './App.css';
import logo from './assets/logo.png';
import facebook from './assets/facebook.png';
import twitter from './assets/twitter.png';
import instagram from './assets/instagram.png';
import toggle from './assets/toggle.png';
import play from './assets/play.png';

function Toggle(){
  var trailer = document.querySelector('.trailer');
  var video = document.querySelector('video');
  trailer.classList.toggle('active');
  video.currentTime = 0;
  video.pause();
}

function App() {
    return (
    <div className="App">
       <header>
       <a href="sg" class="logo"><img src={logo}  style={{transform:"scaleX(-1)"}}
 alt={" "}/></a>
       <div class="toggle"><img src={toggle}  alt={" "} /></div>
       </header>
      <div class="banner">
        <div class="content">
          <h2>Put on a <span>Happy</span> face</h2>
        <p>
        Lorem Ipsum is simply dummy text of the printing and typesetti
        ng industry. Lorem Ipsum has been the industry's standard dummy text ever sinc
        e the 1500s, when an unknown printer took a galley of type and scrambled it to 
        make a type specimen book. It has survived nf Lorem Ipsum.
        </p>
        <a href="st" class="play" onClick={Toggle}  ><img src={play} alt={""} />Watch Trailer</a>
        <div class="slide"></div>
        <ul class="sci">
          <li><a href="st" target="_blank" rel="noopener noreferrer"><img src={facebook} alt={""} /></a></li>
          <li><a href="https://www.youtube.com/channel/UCf2SEZjROb9xZBEgoTbqTmw"target="_blank" rel="noopener noreferrer"><img src={twitter} alt={" "} /></a></li>
          <li><a href="https://www.instagram.com/amyytravels_/" target="_blank" rel="noopener noreferrer" ><img src={instagram} alt={" "} /></a></li>
        </ul>

        </div>
      </div>
      <div class="trailer">
        <video src="trailer.mp4" controls="true"></video>
        <img src="close" class="close " alt={""} onClick={Toggle} />
      </div>

        
    </div>
  );
  

}

export default App;
