/* Google Analytics Code */
var _gaq = _gaq || [];
_gaq.push(['_setAccount', 'UA-39773230-2']);
_gaq.push(['_trackPageview']);

(function() {
  var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
  ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
  var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
})();

//Site improve
(function() {
  var sz = document.createElement('script'); sz.type = 'text/javascript'; sz.async = true;
  sz.src = '//siteimproveanalytics.com/js/siteanalyze_6428.js';
  var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(sz, s);
})();

function msg(){
  var X = document.getElementById("searchinput").value;
  window.open("https://az.gov/search/google/"+X);
}
