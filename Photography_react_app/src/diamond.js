import React from 'react';
import './App.css';
import './diamond/diamonds.css';


function Diamond() {
    return (
    <div className="App">
        <div class="diamond-body">
           <div class="diamond-grid">
                <div class="item"></div>
                <div class="item"></div>
                <div class="item"></div>
                <div class="item"></div>
                <div class="item"></div>
           </div>
         </div>
    </div>
  );

}
<html>
<script src="https://code.jquery.com/jquery-3.5.1.js"></script>
<script src="../src/diamond/jquery.diamonds.js"></script> 
<script type="text/javascript">

$(".diamond-grid").diamonds({
 size : 200, // Size of diamonds in pixels. Both width and height. 
 gap : 5, // Pixels between each square.
 hideIncompleteRow : false, // Hide last row if there are not enough items to fill it completely.
 autoRedraw : true, // Auto redraw diamonds when it detects resizing.
 itemSelector : ".item"// the css selector to use to select diamonds-items.
});
</script>
</html>
export default Diamond;
