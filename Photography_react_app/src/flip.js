import React from 'react';
import './App.css';
import logo from './flipimg/logo.png';
import {Col,Row,Container} from 'reactstrap';
function Flip() {
    return (
    <div className="App">
        <div class="flipbody">
 
        <section>
        <Container>
      <Row>
        <Col xl="3" lg="3" md="6" sm="12" xs="12">
            <div class="flipcard">
                <div class="flipbox">
                    <div class="flipimgBx">
                        <img src={logo} alt={""}/>
                    </div>
                    <div class="flipcontentBx">
                        <div>
                            <h2>Post Title</h2>
                            <p>abcdefghijklajfdhfureifjdsnirejfi nfjifnjirej</p>
                        </div>

                    </div>
                </div>
            </div>
        </Col>
        <Col xl="3" lg="3" md="6" sm="12" xs="12">
            <div class="flipcard">
                <div class="flipbox">
                    <div class="flipimgBx">
                        <img src={logo} alt={""}/>
                    </div>
                    <div class="flipcontentBx">
                        <div>
                            <h2>Post Title</h2>
                            <p>abcdefghijklajfdhfureifjdsnirejfi nfjifnjirej</p>
                        </div>

                    </div>

                </div>
                </div>
        </Col>
        <Col xl="3" lg="3" md="6" sm="12" xs="12">
            <div class="flipcard">
                <div class="flipbox">
                    <div class="flipimgBx">
                        <img src={logo} alt={""}/>
                    </div>
                    <div class="flipcontentBx">
                        <div>
                            <h2>Post Title</h2>
                            <p>abcdefghijklajfdhfureifjdsnirejfi nfjifnjirej</p>
                        </div>

                    </div>

                </div>
                </div>
        </Col>
        <Col xl="3" lg="3" md="6" sm="12" xs="12">
            <div class="flipcard">
                <div class="flipbox">
                    <div class="flipimgBx">
                        <img src={logo} alt={""}/>
                    </div>
                    <div class="flipcontentBx">
                        <div>
                            <h2>Post Title</h2>
                            <p>abcdefghijklajfdhfureifjdsnirejfi nfjifnjirej</p>
                        </div>

                    </div>

                </div>
            </div>
            
        </Col>
      </Row>
 
      </Container>
            </section>
    </div>
    </div>
  );
  

}

export default Flip;
