
#include <Update.h>
#include "AxWebServer.h"
#include "Trace.h"
#include "CoreDefinitions.h"
#include "WiFi.h"
#include "Font.h"
#include "WebPages.h"


/*
 * Server Pages
 */

const char* AxOTAWebServerPage = R"V0G0N(
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="en" xml:lang="en">
<head>
	<link rel="icon" href="icon/apple-touch-icon.png">
	<title>)V0G0N" PRODUCT_NAME R"V0G0N( - Frontend Processor Firmware Update</title>
  <style>
  html { font-family: 'Noto Sans', sans-serif; display: inline-block; margin: 0px auto; text-align: center; }
  a:hover { background: rgb(110, 255, 255); }
  ::selection { background: rgb(110, 255, 255); color: rgb(0,38,117); }
  @charset "UTF-8";


	@font-face {
	font-family: "Fedra Mono Demi";
	src: url("fonts/WF-035979-011333-000062.woff2") format("woff2"), url("fonts/WF-035979-011333-000062.woff") format("woff");
	}




  a.WF-035979-011333-000062 { text-align: center; font-family:"Fedra Mono Demi";}

  </style>
  <meta http-equiv="content-type" content="text/html; charset=utf-8"/>
  <meta name="author" content="SLONline, spol. s r.o."/>
	<meta name="robots" content="all"/>
	<meta name="description" content="Typotheque type foundry: buy and download high quality fonts for print and web directly from the designers. Typefaces for books, magazines, newspapers and corporate identities. OpenType fonts supporting Latin, Greek. Cyrillic, Arabic, Armenian and Hindi."/>
	<meta name="keywords" content="Typotheque, Brioni, Brioni Text, Fedra Arabic, Fedra Hindi, Fedra Mono, Fedra Sans, Fedra Sans Alt, Fedra Sans Condensed, Fedra Sans Condensed Alt, Fedra Sans Display 1, Fedra Sans Display 2, Fedra Serif A, Fedra Serif B, Fedra Serif Display, Fedra Serif Phonetic, Greta Display, Greta Display Narrow, Greta Grande, Greta Grande Narrow, Greta Text, Greta Text Narrow, History, Irma, Irma Slab, Jigsaw, Jigsaw Stencil, Klimax, Nara, Plan Grot Cond Stencil, Plan Grot Condensed, Plan Grotesque, Plan Grotesque Stencil, sans, serif, slab, book, magazine, newspaper, corporate identity, packaging, multilingual, greek, cyrillic, arabic, hindi, devanagari, latin, OpenType, TrueType, WOFF, EOT, fonts, font, typefaces, typeface, type, Peter Bilak"/>
</head>
<body style="background-image: linear-gradient(to bottom right, #002675, #0a0a40); background-repeat: no-repeat; background-size: cover; height: 1000px;">
  <div style="background-color: #FFFFFF; line-height: 100px; position: relative; margin: 0;">
    <a href='/' style='text-decoration: none; padding: 5px;'>
      <svg xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:cc="http://creativecommons.org/ns#" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#" xmlns:svg="http://www.w3.org/2000/svg" xmlns="http://www.w3.org/2000/svg" xmlns:sodipodi="http://sodipodi.sourceforge.net/DTD/sodipodi-0.dtd" xmlns:inkscape="http://www.inkscape.org/namespaces/inkscape" width="77.570328mm" height="14.187629mm" viewBox="0 0 77.570328 14.187629" version="1.1" id="svg66832" inkscape:version="1.0.1 (3bc2e813f5, 2020-09-07)" sodipodi:docname="abrantix-logo-blau.svg">
      <defs id="defs66826">
        <clipPath clipPathUnits="userSpaceOnUse" id="clipPath5245">
          <path d="M 0,6440.818 H 1920 V 0 H 0 Z" id="path5243"/>
        </clipPath>
      </defs>
      <sodipodi:namedview id="base" pagecolor="#ffffff" bordercolor="#666666" borderopacity="1.0" inkscape:pageopacity="0.0" inkscape:pageshadow="2" inkscape:zoom="1.5410448" inkscape:cx="166.5896" inkscape:cy="71.339233" inkscape:document-units="mm" inkscape:current-layer="layer1" inkscape:document-rotation="0" showgrid="false" fit-margin-top="0" fit-margin-left="0" fit-margin-right="0" fit-margin-bottom="0" inkscape:window-width="1254" inkscape:window-height="967" inkscape:window-x="193" inkscape:window-y="76" inkscape:window-maximized="0"/>
      <metadata id="metadata66829">
        <rdf:RDF>
          <cc:Work rdf:about="">
            <dc:format>image/svg+xml</dc:format>
            <dc:type rdf:resource="http://purl.org/dc/dcmitype/StillImage"/>
            <dc:title/>
          </cc:Work>
        </rdf:RDF>
      </metadata>
      <g inkscape:label="Ebene 1" inkscape:groupmode="layer" id="layer1" transform="translate(-23.202931,-149.3883)">
        <g id="g5239" transform="matrix(0.35277777,0,0,-0.35277777,-89.685779,2410.1906)">
          <g id="g5241" clip-path="url(#clipPath5245)">
            <g id="g5247" transform="translate(347.5045,6368.3569)">
              <path d="m 0,0 v 16.901 c 0,6.657 -3.739,10.088 -11.113,10.088 h -14.599 v -5.582 h 11.881 c 4.508,0 6.454,-0.922 6.454,-4.353 v -0.665 h -9.373 c -7.528,0 -10.755,-2.358 -10.755,-8.605 0,-4.967 2.972,-7.784 8.35,-7.784 L 0,0 m -7.325,5.427 h -8.913 c -2.61,0 -3.89,0.308 -3.89,2.561 0,2.408 1.383,3.023 4.402,3.023 h 8.401 z" style="fill:#002675;fill-opacity:1;fill-rule:nonzero;stroke:none" id="path5249"/>
            </g>
            <g id="g5251" transform="translate(368.6521,6373.7837)">
              <path d="m 0,0 h -8.91 v 4.647 h 0.052 v 0.666 h 9.37 c 0.492,0 0.96,0.014 1.414,0.03 C 3.263,4.99 3.893,4.184 3.893,2.562 3.893,0.308 2.613,0 0,0 M -8.91,16.271 H 0 c 2.613,0 3.893,-0.305 3.893,-2.56 0,-1.623 -0.63,-2.427 -1.97,-2.782 -0.451,0.022 -0.921,0.031 -1.411,0.031 h -9.37 v 0.667 L -8.91,11.624 Z m 20.18,-2.354 c 0,4.968 -2.971,7.784 -8.349,7.784 H -16.234 V -5.427 H 2.921 c 5.378,0 8.349,2.816 8.349,7.784 0,2.536 -1.661,4.424 -2.794,5.779 1.133,1.357 2.794,3.244 2.794,5.781" style="fill:#002675;fill-opacity:1;fill-rule:nonzero;stroke:none" id="path5253"/>
            </g>
            <g id="g5255" transform="translate(400.76,6384.0293)">
              <path d="m 0,0 v 3.48 c 0,2.409 -0.82,2.665 -3.122,2.665 h -5.711 v -21.817 h -7.12 v 26.989 h 15.185 c 5.634,0 7.581,-1.793 7.581,-6.813 L 6.813,0 H 0" style="fill:#002675;fill-opacity:1;fill-rule:nonzero;stroke:none" id="path5257"/>
            </g>
            <g id="g5259" transform="translate(438.0324,6368.3569)">
              <path d="m 0,0 v 16.901 c 0,6.657 -3.739,10.088 -11.116,10.088 h -14.593 v -5.582 h 11.881 c 4.508,0 6.453,-0.922 6.453,-4.353 v -0.665 h -9.374 c -7.528,0 -10.754,-2.358 -10.754,-8.605 0,-4.967 2.971,-7.784 8.351,-7.784 L 0,0 m -7.325,5.427 h -8.911 c -2.613,0 -3.89,0.308 -3.89,2.561 0,2.408 1.381,3.023 4.403,3.023 h 8.398 z" style="fill:#002675;fill-opacity:1;fill-rule:nonzero;stroke:none" id="path5261"/>
            </g>
            <g id="g5263" transform="translate(461.8479,6368.3569)">
              <path d="m 0,0 v 16.235 c 0,3.738 -0.666,4.814 -4.714,4.814 h -5.734 V 0 h -7.119 v 26.989 h 13.418 c 7.991,0 11.266,-2.713 11.266,-9.885 L 7.117,0 H 0" style="fill:#002675;fill-opacity:1;fill-rule:nonzero;stroke:none" id="path5265"/>
            </g>
            <g id="g5267" transform="translate(488.5573,6389.019)">
              <path d="M 0,0 V -20.662 H -7.991 V 0 h -8.682 V 6.399 H 8.729 V 0 Z" style="fill:#002675;fill-opacity:1;fill-rule:nonzero;stroke:none" id="path5269"/>
            </g>
            <path d="m 501.064,6395.346 h 7.476 v -26.989 h -7.476 z" style="fill:#002675;fill-opacity:1;fill-rule:nonzero;stroke:none" id="path5271"/>
            <g id="g5273" transform="translate(529.8989,6381.6729)">
              <path d="M 0,0 9.831,-13.316 H 1.534 l -5.685,7.836 -5.735,-7.836 h -8.295 l 9.983,13.469 -9.983,13.52 h 8.245 l 5.785,-8.143 5.943,8.143 h 8.193 z" style="fill:#002675;fill-opacity:1;fill-rule:nonzero;stroke:none" id="path5275"/>
            </g>
            <g id="g5277" transform="translate(508.8394,6404.4966)">
              <path d="M 0,0 C 0,2.45 -1.614,4.077 -4.17,4.077 -6.737,4.077 -8.351,2.45 -8.351,0 c 0,-2.435 1.614,-4.063 4.181,-4.063 C -1.585,-4.063 0,-2.435 0,0" style="fill:#002675;fill-opacity:1;fill-rule:nonzero;stroke:none" id="path5279"/>
            </g>
          </g>
        </g>
      </g>
    </svg>
  </a>
  <a class="WF-035979-011333-000062" style="color: rgb(0, 55, 142); font-size: 0.9474em; font-weight: 600; cursor: pointer; text-decoration: none; margin-left: 100px; margin-right: 50px; padding: 5px 5px;" href="/robot-control">robot control_</a>
  <a class="WF-035979-011333-000062" style="color: rgb(0, 55, 142); font-size: 0.9474em; font-weight: 600; cursor: pointer; text-decoration: none; margin-left: 100px; margin-right: 50px; padding: 5px 5px;" href="/networkconfig">network configuration_</a>
  <a class="WF-035979-011333-000062" style="color: rgb(0, 55, 142); background: rgb(110, 255, 255); font-size: 0.9474em; font-weight: 600; cursor: pointer; text-decoration: none; margin-left: 50px; margin-right: 50px; padding: 5px 5px;" href="/esp32update">frontend processor firmware update_</a>
  <a class="WF-035979-011333-000062" style="color: rgb(0, 55, 142); font-size: 0.9474em; font-weight: 600; cursor: pointer; text-decoration: none; margin-left: 50px; margin-right: 50px; padding: 5px 5px;" href="/camera">camera_</a>
  <a class="WF-035979-011333-000062" style="color: rgb(0, 55, 142); font-size: 0.9474em; font-weight: 600; cursor: pointer; text-decoration: none; margin-left: 100px; margin-right: 50px; padding: 5px 5px;" href="/about">about_</a>
  </div>
  <div style="color: white;">
    <h2>)V0G0N" PRODUCT_NAME R"V0G0N(</h2>
    <h3>Frontend Processor Firmware Update</h3>
    <form method='POST' action='#' enctype='multipart/form-data' id='upload_form'>
      <input type='file' id="actual-btn" name='update' hidden/>
      <label style="color: rgb(110, 255, 255); background: rgb(0, 55, 142); cursor: pointer; font-size: 17px;" for="actual-btn">Choose File</label>
      </br></br>
      <input style="color: rgb(110, 255, 255); background: rgb(0, 55, 142); cursor: pointer; border: none; font-size: 17px;" type='submit' value='Update'/>
    </form>
  </div>
</body></html>
)V0G0N";


const char* AxWebServerNetworkConfigPage = R"V0G0N(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <!-- App title -->
    <title>Abrantix AG - Robot Control</title>

    <link rel="apple-touch-icon" sizes="180x180" href="icon/apple-touch-icon.png">
    <link rel="icon" type="image/png" sizes="32x32" href="icon/favicon-32x32.png">
    <link rel="icon" type="image/png" sizes="16x16" href="icon/favicon-16x16.png">

    <!-- Link css file -->
    <link rel="stylesheet" href="style/style.css">

</head>
<body>
    
    <!-- Navigation bar -->
    <header class="header">
        <!-- Logo -->
        <a href="#" class="logo"><img src="image/ax_claim_white.png" alt="Abrantix" height="40"></a>

        <!-- Hamburger icon -->
        <input class="side-menu" type="checkbox" id="side-menu"/>
        <label class="hamb" for="side-menu"><span class="hamb-line"></span></label>

        <!-- Menu -->
        <nav class="nav">
          <ul class="menu">
                <li><a href="home.html">Robots</a></li>
                <li><a href="#">Camera Settings</a></li>
                <li><a href="#">Network Configuration</a></li>
                <li><a href="#">Software</a></li>
            </ul>
        </nav>
    </header>

    <!-- Main content -->
    <main>
        <article>
          <div class="networkconfig-grid">
			 <form action='networkconfig'>
			  <label for='uiPort'>TCP Port</label>
			  <div class='noBreakGroup'>
			  <input type='text' size='5' maxlength='5' id='uiPort' name='Port' value='%u'>
			  </div>
			  <br/>
			   <input type='radio' id='n2' name='networktype' value='2' onclick='EnableDisable()' %s>
			   <label for='n2'>Wireless Client (STA) DHCP</label><br/>
			   <input type='radio' id='n3' name='networktype' value='3' onclick='EnableDisable()' %s>
			   <label for='n3'>Wireless AP</label><br/>
			   <br/>
			   <div id='wifibox'>
				 <label for='uiSSID'>SSID</label>
				 <div class='noBreakGroup'>
				   <input type='text' list='uiSSID' name='SSID' style='width: 385px;' />
  			      <datalist id='uiSSID'  style='width: 385px;'>
				  </datalist>
				  </div>
				  <label for='uiPassword'>WIFI Password</label>
				  <div class='noBreakGroup'>
				  <input type='password' size='63' maxlength='63' id='uiPassword' name='Password' value=''>
				  </div>
				  </div>
				  <br/><br;/>
				  <input style="color: rgb(110, 255, 255); background: rgb(0, 55, 142); cursor: pointer; border: none; font-size: 17px;" type='submit' value='Apply Changes'>
				  <br/><br/>
				  </div>
				  <br/><br/>
				  </div>
				  </form>
          </div>

        </article>
    </main>
  <script>
  </script>
</body>
</html>  
)V0G0N";

const char* AxOTAWebServerNetworkConfigPagePart2 = R"V0G0N(
  </datalist>
  </div>
  <label for='uiPassword'>WIFI Password</label>
  <div class='noBreakGroup'>
  <input type='password' size='63' maxlength='63' id='uiPassword' name='Password' value=''>
  </div>
  </div>
  <br/><br;/>
  <input style="color: rgb(110, 255, 255); background: rgb(0, 55, 142); cursor: pointer; border: none; font-size: 17px;" type='submit' value='Apply Changes'>
  <br/><br/>
  </div>
  <br/><br/>
  </div>
  </form>
  </div>
  </body>
  </html>
)V0G0N";


const char* AboutPage = R"V0G0N(
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="en" xml:lang="en">
<head>
  <link rel="icon" href="https://www.abrantix.com/apple-touch-icon.png">
  <title>)V0G0N" PRODUCT_NAME R"V0G0N(- Main</title>
  <style>
  html { font-family: 'Noto Sans', sans-serif; display: inline-block; margin: 0px auto; text-align: center; }
  a:hover { background: rgb(110, 255, 255); }
  a { color: rgb(110, 255, 255); }
  ::selection { background: rgb(110, 255, 255); color: rgb(0,38,117); }
  @charset "UTF-8";


	@font-face {
	font-family: Fedra Mono Demi;
	src: url("fonts/WF-035979-011333-000062.woff"), url("fonts/WF-035979-011333-000062.woff2");
	}




  a.WF-035979-011333-000062 { text-align: center; font-family: Fedra Mono Demi; }

  </style>
  <meta http-equiv="content-type" content="text/html; charset=utf-8"/>
  <meta name="author" content="SLONline, spol. s r.o."/>
	<meta name="robots" content="all"/>
	<meta name="description" content="Typotheque type foundry: buy and download high quality fonts for print and web directly from the designers. Typefaces for books, magazines, newspapers and corporate identities. OpenType fonts supporting Latin, Greek. Cyrillic, Arabic, Armenian and Hindi."/>
	<meta name="keywords" content="Typotheque, Brioni, Brioni Text, Fedra Arabic, Fedra Hindi, Fedra Mono, Fedra Sans, Fedra Sans Alt, Fedra Sans Condensed, Fedra Sans Condensed Alt, Fedra Sans Display 1, Fedra Sans Display 2, Fedra Serif A, Fedra Serif B, Fedra Serif Display, Fedra Serif Phonetic, Greta Display, Greta Display Narrow, Greta Grande, Greta Grande Narrow, Greta Text, Greta Text Narrow, History, Irma, Irma Slab, Jigsaw, Jigsaw Stencil, Klimax, Nara, Plan Grot Cond Stencil, Plan Grot Condensed, Plan Grotesque, Plan Grotesque Stencil, sans, serif, slab, book, magazine, newspaper, corporate identity, packaging, multilingual, greek, cyrillic, arabic, hindi, devanagari, latin, OpenType, TrueType, WOFF, EOT, fonts, font, typefaces, typeface, type, Peter Bilak"/>
	<title>Typotheque Web Fonts Demo</title>
	<link rel="stylesheet" type="text/css" href="./style.css"/>
</head>
<body style="background-image: linear-gradient(to bottom right, #002675, #0a0a40); background-repeat: no-repeat; background-size: cover; height: 1000px;">
  <div style="background-color: #FFFFFF; line-height: 100px; position: relative; margin: 0;">
    <a href='/' style='text-decoration: none; padding: 5px;'>
      <svg xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:cc="http://creativecommons.org/ns#" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#" xmlns:svg="http://www.w3.org/2000/svg" xmlns="http://www.w3.org/2000/svg" xmlns:sodipodi="http://sodipodi.sourceforge.net/DTD/sodipodi-0.dtd" xmlns:inkscape="http://www.inkscape.org/namespaces/inkscape" width="77.570328mm" height="14.187629mm" viewBox="0 0 77.570328 14.187629" version="1.1" id="svg66832" inkscape:version="1.0.1 (3bc2e813f5, 2020-09-07)" sodipodi:docname="abrantix-logo-blau.svg">
      <defs id="defs66826">
        <clipPath clipPathUnits="userSpaceOnUse" id="clipPath5245">
          <path d="M 0,6440.818 H 1920 V 0 H 0 Z" id="path5243"/>
        </clipPath>
      </defs>
      <sodipodi:namedview id="base" pagecolor="#ffffff" bordercolor="#666666" borderopacity="1.0" inkscape:pageopacity="0.0" inkscape:pageshadow="2" inkscape:zoom="1.5410448" inkscape:cx="166.5896" inkscape:cy="71.339233" inkscape:document-units="mm" inkscape:current-layer="layer1" inkscape:document-rotation="0" showgrid="false" fit-margin-top="0" fit-margin-left="0" fit-margin-right="0" fit-margin-bottom="0" inkscape:window-width="1254" inkscape:window-height="967" inkscape:window-x="193" inkscape:window-y="76" inkscape:window-maximized="0"/>
      <metadata id="metadata66829">
        <rdf:RDF>
          <cc:Work rdf:about="">
            <dc:format>image/svg+xml</dc:format>
            <dc:type rdf:resource="http://purl.org/dc/dcmitype/StillImage"/>
            <dc:title/>
          </cc:Work>
        </rdf:RDF>
      </metadata>
      <g inkscape:label="Ebene 1" inkscape:groupmode="layer" id="layer1" transform="translate(-23.202931,-149.3883)">
        <g id="g5239" transform="matrix(0.35277777,0,0,-0.35277777,-89.685779,2410.1906)">
          <g id="g5241" clip-path="url(#clipPath5245)">
            <g id="g5247" transform="translate(347.5045,6368.3569)">
              <path d="m 0,0 v 16.901 c 0,6.657 -3.739,10.088 -11.113,10.088 h -14.599 v -5.582 h 11.881 c 4.508,0 6.454,-0.922 6.454,-4.353 v -0.665 h -9.373 c -7.528,0 -10.755,-2.358 -10.755,-8.605 0,-4.967 2.972,-7.784 8.35,-7.784 L 0,0 m -7.325,5.427 h -8.913 c -2.61,0 -3.89,0.308 -3.89,2.561 0,2.408 1.383,3.023 4.402,3.023 h 8.401 z" style="fill:#002675;fill-opacity:1;fill-rule:nonzero;stroke:none" id="path5249"/>
            </g>
            <g id="g5251" transform="translate(368.6521,6373.7837)">
              <path d="m 0,0 h -8.91 v 4.647 h 0.052 v 0.666 h 9.37 c 0.492,0 0.96,0.014 1.414,0.03 C 3.263,4.99 3.893,4.184 3.893,2.562 3.893,0.308 2.613,0 0,0 M -8.91,16.271 H 0 c 2.613,0 3.893,-0.305 3.893,-2.56 0,-1.623 -0.63,-2.427 -1.97,-2.782 -0.451,0.022 -0.921,0.031 -1.411,0.031 h -9.37 v 0.667 L -8.91,11.624 Z m 20.18,-2.354 c 0,4.968 -2.971,7.784 -8.349,7.784 H -16.234 V -5.427 H 2.921 c 5.378,0 8.349,2.816 8.349,7.784 0,2.536 -1.661,4.424 -2.794,5.779 1.133,1.357 2.794,3.244 2.794,5.781" style="fill:#002675;fill-opacity:1;fill-rule:nonzero;stroke:none" id="path5253"/>
            </g>
            <g id="g5255" transform="translate(400.76,6384.0293)">
              <path d="m 0,0 v 3.48 c 0,2.409 -0.82,2.665 -3.122,2.665 h -5.711 v -21.817 h -7.12 v 26.989 h 15.185 c 5.634,0 7.581,-1.793 7.581,-6.813 L 6.813,0 H 0" style="fill:#002675;fill-opacity:1;fill-rule:nonzero;stroke:none" id="path5257"/>
            </g>
            <g id="g5259" transform="translate(438.0324,6368.3569)">
              <path d="m 0,0 v 16.901 c 0,6.657 -3.739,10.088 -11.116,10.088 h -14.593 v -5.582 h 11.881 c 4.508,0 6.453,-0.922 6.453,-4.353 v -0.665 h -9.374 c -7.528,0 -10.754,-2.358 -10.754,-8.605 0,-4.967 2.971,-7.784 8.351,-7.784 L 0,0 m -7.325,5.427 h -8.911 c -2.613,0 -3.89,0.308 -3.89,2.561 0,2.408 1.381,3.023 4.403,3.023 h 8.398 z" style="fill:#002675;fill-opacity:1;fill-rule:nonzero;stroke:none" id="path5261"/>
            </g>
            <g id="g5263" transform="translate(461.8479,6368.3569)">
              <path d="m 0,0 v 16.235 c 0,3.738 -0.666,4.814 -4.714,4.814 h -5.734 V 0 h -7.119 v 26.989 h 13.418 c 7.991,0 11.266,-2.713 11.266,-9.885 L 7.117,0 H 0" style="fill:#002675;fill-opacity:1;fill-rule:nonzero;stroke:none" id="path5265"/>
            </g>
            <g id="g5267" transform="translate(488.5573,6389.019)">
              <path d="M 0,0 V -20.662 H -7.991 V 0 h -8.682 V 6.399 H 8.729 V 0 Z" style="fill:#002675;fill-opacity:1;fill-rule:nonzero;stroke:none" id="path5269"/>
            </g>
            <path d="m 501.064,6395.346 h 7.476 v -26.989 h -7.476 z" style="fill:#002675;fill-opacity:1;fill-rule:nonzero;stroke:none" id="path5271"/>
            <g id="g5273" transform="translate(529.8989,6381.6729)">
              <path d="M 0,0 9.831,-13.316 H 1.534 l -5.685,7.836 -5.735,-7.836 h -8.295 l 9.983,13.469 -9.983,13.52 h 8.245 l 5.785,-8.143 5.943,8.143 h 8.193 z" style="fill:#002675;fill-opacity:1;fill-rule:nonzero;stroke:none" id="path5275"/>
            </g>
            <g id="g5277" transform="translate(508.8394,6404.4966)">
              <path d="M 0,0 C 0,2.45 -1.614,4.077 -4.17,4.077 -6.737,4.077 -8.351,2.45 -8.351,0 c 0,-2.435 1.614,-4.063 4.181,-4.063 C -1.585,-4.063 0,-2.435 0,0" style="fill:#002675;fill-opacity:1;fill-rule:nonzero;stroke:none" id="path5279"/>
            </g>
          </g>
        </g>
      </g>
    </svg>
  <a href='/'>
  <a class="WF-035979-011333-000062" style="color: rgb(0, 55, 142); font-size: 0.9474em; font-weight: 600; cursor: pointer; text-decoration: none; margin-left: 100px; margin-right: 50px; padding: 5px 5px;" href="/robot-control">robot control_</a>
  <a class="WF-035979-011333-000062" style="color: rgb(0, 55, 142); font-size: 0.9474em; font-weight: 600; cursor: pointer; text-decoration: none; margin-left: 100px; margin-right: 50px; padding: 5px 5px;" href="/networkconfig">network configuration_</a>
  <a class="WF-035979-011333-000062" style="color: rgb(0, 55, 142); font-size: 0.9474em; font-weight: 600; cursor: pointer; text-decoration: none; margin-left: 50px; margin-right: 50px; padding: 5px 5px;" href="/esp32update">frontend processor firmware update_</a>
  <a class="WF-035979-011333-000062" style="color: rgb(0, 55, 142); font-size: 0.9474em; font-weight: 600; cursor: pointer; text-decoration: none; margin-left: 50px; margin-right: 50px; padding: 5px 5px;" href="/camera">camera_</a>
  <a class="WF-035979-011333-000062" style="color: rgb(0, 55, 142); background: rgb(110, 255, 255); font-size: 0.9474em; font-weight: 600; cursor: pointer; text-decoration: none; margin-left: 100px; margin-right: 50px; padding: 5px 5px;" href="/about">about_</a>
  </div>
  <div style="color: white;">
    <h2>License</h2>
    </br></br>
    <table style="margin-left: auto; margin-right: auto;">
      <tr>
        <th>Name</th>
        <th>Source</th>
        <th>License</th>
      </tr>
      <tr>
        <td>Arduino</td>
        <td>Arduino IDE</td>
        <td>LGPL</td>
      </tr>
      <tr>
        <td>Wire.h</td>
        <td>Arduino IDE</td>
        <td>LGPL</td>
      </tr>
      <tr>
        <td>MCP23017.h</td>
        <td><a href="https://github.com/blemasle/arduino-mcp23017">https://github.com/blemasle/arduino-mcp23017</td>
        <td>MIT</td>
      </tr>
      <tr>
        <td>Adafruit_SSD1306</td>
        <td><a href="https://github.com/adafruit/Adafruit-GFX-Library">https://github.com/adafruit/Adafruit-GFX-Library</td>
        <td>BSD</td>
      </tr>
      <tr>
        <td>Adafruit_GFX_Library</td>
        <td><a href="https://github.com/adafruit/Adafruit-GFX-Library">https://github.com/adafruit/Adafruit-GFX-Library</td>
        <td>BSD</td>
      </tr>
      <tr>
        <td>Adafruit_BusIO</td>
        <td><a href="https://github.com/adafruit/Adafruit_BusIO">https://github.com/adafruit/Adafruit_BusIO</td>
        <td>MIT</td>
      </tr>
      <tr>
        <td>ArduinoECCX08.h</td>
        <td>Arduino IDE</td>
        <td>LGPL</td>
      </tr>
      <tr>
        <td>EEPROM.h</td>
        <td>Arduino IDE</td>
        <td>LGPL</td>
      </tr>
      <tr>
        <td>ESPmDNS.h</td>
        <td><a href="https://github.com/espressif/arduino-esp32">https://github.com/espressif/arduino-esp32</td>
        <td>MIT</td>
      </tr>
      <tr>
        <td>FS.h</td>
        <td><a href="https://github.com/espressif/arduino-esp32">https://github.com/espressif/arduino-esp32</td>
        <td>MIT</td>
      </tr>
      <tr>
        <td>SD.h</td>
        <td><a href="https://github.com/espressif/arduino-esp32">https://github.com/espressif/arduino-esp32</td>
        <td>MIT</td>
      </tr>
      <tr>
        <td>SPI.h</td>
        <td>Arduino IDE</td>
        <td>LGPL</td>
      </tr>
      <tr>
        <td>WiFi.h</td>
        <td><a href="https://github.com/espressif/arduino-esp32">https://github.com/espressif/arduino-esp32</td>
        <td>LGPL</td>
      </tr>
      <tr>
        <td>ETH.h</td>
        <td><a href="https://github.com/espressif/arduino-esp32">https://github.com/espressif/arduino-esp32</td>
        <td>LGPL</td>
      </tr>
      <tr>
        <td>AsyncTCP.h</td>
        <td><a href="https://github.com/me-no-dev">https://github.com/me-no-dev</td>
        <td>LGPL</td>
      </tr>
      <tr>
        <td>ESPAsyncWebServer.h</td>
        <td><a href="https://github.com/me-no-dev">https://github.com/me-no-dev</td>
        <td>LGPL</td>
      </tr>
      <tr>
        <td>ECCX08.h</td>
        <td>Arduino IDE</td>
        <td>LGPL</td>
      </tr>
      <tr>
        <td>ESP32AVRISP.h</td>
        <td>Abrantix - but mainly based on <a href="https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266AVRISP">https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266AVRISP</td>
        <td>BSD</td>
      </tr>
      <tr>
        <td>SPI.h</td>
        <td>Arduino IDE</td>
        <td>LGPL</td>
      </tr>
      <tr>
        <td>esp32-camera</td>
        <td><a href="https://github.com/espressif/esp32-camera">https://github.com/espressif/esp32-camera</td>
        <td>Apache</td>
      </tr>
      <tr>
        <td>Ax-PN7150</td>
        <td><a href="https://github.com/ArminJo/Github-Actions">https://github.com/ArminJo/Github-Actions</td>
        <td>MIT</td>
      </tr>
      <tr>
        <td>EspSoftwareSerial</td>
        <td><a href="https://github.com/plerup/espsoftwareserial">https://github.com/plerup/espsoftwareserial</td>
        <td>LGPL</td>
      </tr>
      <tr>
        <td>AsyncDelay</td>
        <td><a href="https://github.com/stevemarple/AsyncDelay">https://github.com/stevemarple/AsyncDelay</td>
        <td>LGPL</td>
      </tr>
      <tr>
        <td>SoftWire</td>
        <td><a href="https://github.com/stevemarple/SoftWire">https://github.com/stevemarple/SoftWire</td>
        <td>LGPL</td>
      </tr>
      <tr>
        <td>DFRobot_CH423</td>
        <td><a href="https://github.com/DFRobot/DFRobot_CH423">https://github.com/DFRobot/DFRobot_CH423</td>
        <td>MIT</td>
      </tr>
    </table>
  </div>
</body></html>
)V0G0N";