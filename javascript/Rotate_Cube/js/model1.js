const Point2D= function(x,y) {this.x=x;this.y=y;};
const Point3D= function(x,y,z) {this.x=x;this.y=y;this.z=z;};

//------------------------------Class Cube Defined--------------------------------------
const Cube=function(x,y,z,size) {
    Point3D.call(this,x,y,z);
    size *=0.5;
    this.vertices=[ new Point3D (x-size,y-size,z-size),
                    new Point3D (x+size,y-size,z-size),
                    new Point3D (x+size,y+size,z-size),
                    new Point3D (x-size,y+size,z-size),
                    new Point3D (x-size,y-size,z+size),
                    new Point3D (x+size,y-size,z+size),
                    new Point3D (x+size,y+size,z+size),
                    new Point3D (x-size,y+size,z+size),                    
                ];
    this.faces=[ [0,1,2,3], [0,4,5,1],[1,5,6,2],[0,3,7,4],[3,2,6,7],[4,7,6,5] ];
};
Cube.prototype={
    //Rotate around X-axis
    rotateX:function(radian) {
        var cosine=Math.cos(radian);
        var sine=Math.sin(radian);

        for(let ind=0;ind<this.vertices.length;ind++)
        {
            let p=this.vertices[ind];
            
            let y= (p.y-this.y)*cosine -(p.z-this.z)*sine;
            let z= (p.y-this.y)*sine +(p.z-this.z)*cosine;
            p.y=y+this.y;
            p.z=z+this.z;
        }
    },
    //Rotate around Y-axis
    rotateY:function(radian) {
        var cosine=Math.cos(radian);
        var sine=Math.sin(radian);

        for(let ind=0;ind<this.vertices.length;ind++)
        {
            let p=this.vertices[ind];
            
            let z= (p.z-this.z)*cosine -(p.x-this.x)*sine;
            let x= (p.z-this.z)*sine +(p.x-this.x)*cosine;
            p.x=x+this.x;
            p.z=z+this.z;
        }
        
    }
};


//--------------------------------------------------------------------------------------

var context = document.querySelector('canvas').getContext('2d');
var pointer=new Point2D(0,0);
var cube =new Cube(0,0,400,200);

var height=document.documentElement.clientHeight;
var width= document.documentElement.clientWidth;

//------------------------Function to return points to be projected------------------------
function project(points3D,width,height) {
    var points2d= new Array(points3D.length);
    var focal_length=200;
    for(let ind=0;ind<points3D.length;ind++)
    {
        let p1=points3D[ind];
        let x=p1.x*(focal_length/p1.z)+width*0.5;
        let y=p1.y*(focal_length/p1.z)+height*0.5;
        points2d[ind]=new Point2D(x,y);
    }
    return points2d;
}
//-----------------------------------------------------------------------------------------


//------------------------Function to print points and lines to be projected------------------------
function loop() {
    window.requestAnimationFrame(loop);
    height=document.documentElement.clientHeight;
    width= document.documentElement.clientWidth;
    context.canvas.height=height;
    context.canvas.width=width;
    context.fillStyle ="#FFF300 ";
    context.fillRect(0,0,width,height);

    context.strokeStyle="#000000";
    context.fillStyle="#0080F0";
    
    cube.rotateY(-pointer.x*0.0001);
    cube.rotateX(pointer.y*0.0001);
    var vertices=project(cube.vertices,width,height);

    for(let ind=cube.faces.length-1;ind>=0;ind--)
    {
        let face=cube.faces[ind];
        let p1=cube.vertices[face[0]];
        let p2=cube.vertices[face[1]];
        let p3=cube.vertices[face[2]];
        let v1=new Point3D(p2.x-p1.x,p2.y-p1.y,p2.z-p1.z);                                  //Vector 1 on the face  w.r.t Universe
        let v2=new Point3D(p3.x-p1.x,p3.y-p1.y,p3.z-p1.z);                                  //Vector 2 on the face  w.r.t Universe
        let n=new Point3D(v1.y*v2.z-v2.y*v1.z,-v1.x*v2.z+v2.x*v1.z,-v1.y*v2.x+v2.y*v1.x);   //Normal Vector : Cross Product   w.r.t Universe

        if((0-p1.x)*n.x+(0-p1.y)*n.y+(0-p1.z)*n.z <= 0 )    //DotProduct   We are doing 0-p1.x and so on to get dotfrodult of vector w.r.t Universe
        {
            context.beginPath();
            context.moveTo(vertices[face[0]].x,vertices[face[0]].y);
            context.lineTo(vertices[face[1]].x,vertices[face[1]].y);
            context.lineTo(vertices[face[2]].x,vertices[face[2]].y);
            context.lineTo(vertices[face[3]].x,vertices[face[3]].y);
            context.closePath();
            context.fill();
            context.stroke();

        }

    }
}
//-------------------------------------------------------------------------------------------------
loop();

window.addEventListener("click", (event) => {
    
    pointer.x=event.pageX -width*0.5;
    pointer.y=event.pageY-height*0.5;
    console.log(event);
    
});