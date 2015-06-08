<?php
include '../lib/WideImage.php';

$hex = "#000000";

if(isset($_GET["color"])) {
  if($_GET["color"] != "") {
    $color = $_GET["color"];
  }
}

if (ctype_xdigit($color)) { //Is hex?
  $hex = $color;
  //echo "Hex color: " .$color.'<br />';
}
else {
  $hex = rgb2hex($color);
  //echo "RGB color: " . $color .'<br />Hex conversion: ' . $hex . '<br />';
}

//exit;

$rgb = hex2rgb($hex);

$im_handle = imagecreatefrompng('../img/icons/icon-arrow.png');

// 1. Load Image
$original = WideImage::load($im_handle);

// 2. Get Transparency Mask
$mask = $original->getMask();

// 3. Dispose Original
$original->destroy();

// 4. Create New Image
$colorized = WideImage::createTrueColorImage($mask->getWidth(), $mask->getHeight());

// 5. Colorize Image
$bg = $colorized->allocateColor($rgb[0], $rgb[1], $rgb[2]);
$colorized->fill(0, 0, $bg);

// 6. Apply Transparency Mask
$colorized = $colorized->applyMask($mask);

// 7. Dispose mask
$mask->destroy();

// 8a. Save colorized (Possible to incorporate caching here.)
//$colorized->save($new_image_name);

// 8b. Serve colorized
$colorized->output('png');

//echo rgb2hex($hex) . '<br />';


// 9. Dispose colorized
$colorized->destroy();






function hex2rgb($hex) {
  $hex = str_replace("#", "", $hex);

  if(strlen($hex) == 3) {
    $r = hexdec(substr($hex,0,1).substr($hex,0,1));
    $g = hexdec(substr($hex,1,1).substr($hex,1,1));
    $b = hexdec(substr($hex,2,1).substr($hex,2,1));
  } 
  else {
    $r = hexdec(substr($hex,0,2));
    $g = hexdec(substr($hex,2,2));
    $b = hexdec(substr($hex,4,2));
  }
  $rgb = array($r, $g, $b);
  return $rgb; // returns an array with the rgb values
}


function rgb2hex($input) {
  // Remove named array keys if input comes from something like Color::hex2rgb().
  if (is_array($input)) {
    $rgb = array_values($input);
  }
  // Parse string input in CSS notation ('10, 20, 30').
  elseif (is_string($input)) {
    preg_match('/(\d+), ?(\d+), ?(\d+)/', $input, $rgb);
    array_shift($rgb);
  }

  $out = 0;
  foreach ($rgb as $k => $v) {
    $out |= $v << (16 - $k * 8);
  }

  return '#' . str_pad(dechex($out), 6, 0, STR_PAD_LEFT);
}


?>
