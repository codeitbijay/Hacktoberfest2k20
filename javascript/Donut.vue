<template>
  <pre id="d" style="background-color:#000; color:#ccc; font-size: 10pt;">{{donut}}</pre>
</template>

<script>
export default {
  name: 'Donut',
  props: {
  },
  data() {
    return {
        tmr1: undefined,
        A: 1,
        B: 1,
        donut: ""
    }
  },
  mounted() {
        
    console.log("donut start")
    
    if(this.$data.tmr1 === undefined) {
        this.$data.tmr1 = setInterval(this.asciiframe, 50);
    } else {
        clearInterval(this.$data.tmr1);
        this.$data.tmr1 = undefined;
    }
    //courtesy of https://www.a1k0n.net/2011/07/20/donut-math.html
    // This is copied, pasted, reformatted, and ported directly from the original
    // donut.c code
  },
  methods: {
    asciiframe: function() {
        var b=[];
        var z=[];
        this.$data.A += 0.07;
        this.$data.B += 0.03;
        var cA=Math.cos(this.$data.A), sA=Math.sin(this.$data.A),
            cB=Math.cos(this.$data.B), sB=Math.sin(this.$data.B);
        for(var k=0;k<1760;k++) {
            b[k]=k%80 == 79 ? "\n" : " ";
            z[k]=0;
        }
        for(var j=0;j<6.28;j+=0.07) { // j <=> theta
            var ct=Math.cos(j),st=Math.sin(j);
            for(var i=0; i<6.28; i += 0.02) {   // i <=> phi
            var sp=Math.sin(i),cp=Math.cos(i),
                h=ct+2, // R1 + R2*cos(theta)
                D=1/(sp*h*sA+st*cA+5), // this is 1/z
                t=sp*h*cA-st*sA; // this is a clever factoring of some of the terms in x' and y'

            var x=0|(40+30*D*(cp*h*cB-t*sB)),
                y=0|(12+15*D*(cp*h*sB+t*cB)),
                o=x+80*y,
                N=0|(8*((st*sA-sp*ct*cA)*cB-sp*ct*sA-st*cA-cp*ct*sB));
            if(y<22 && y>=0 && x>=0 && x<79 && D>z[o])
            {
                z[o]=D;
                b[o]=".,-~:;=!*#$@"[N>0?N:0];
            }
            }
        }
        this.$data.donut = b.join("");
    },
  }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped lang="less">
pre {
  width: 100%;
  overflow:hidden;
  display: flex;
  flex-wrap: nowrap;
  align-content: center;
  align-items: center;
  justify-items: center;
  justify-content: center;
  text-align: center;
}
</style>
