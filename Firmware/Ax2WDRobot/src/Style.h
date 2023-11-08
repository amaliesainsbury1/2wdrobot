/* Style.h */

/* style.css */

const char* Style_Css = R"V0G0N(

@font-face {
    font-family: "Fedra Mono Demi";
    src: url("../fonts/WF-035979-011333-000062.woff2") format("woff2"), url("fonts/WF-035979-011333-000062.woff") format("woff");
}

/* Theming */
:root{
    --color-blue0-100: rgba(0,38,117,1);
    --color-blue0-110: rgba(0,34,105,1);
    --color-blue0-90: rgba(26,60,131,1);
    --color-blue0-50: rgba(128,147,186,1);
    --color-blue0-10: rgba(230,233,241,1);
    --color-blue0-5: rgba(242,244,248,1);

    --color-blue1-100: rgba(10,10,64,1);

    --color-blue2-100: rgba(0,56,143,1);

    --color-blue3-100: rgba(0,105,191,1);
    --color-blue3-110: rgba(0,95,172,1);
    --color-blue3-90: rgba(25,120,197,1);
    --color-blue3-10: rgba(230,240,249,1);
    --color-blue3-5: rgba(242,248,252,1);

    --color-blue4-100: rgba(0,171,245,1);
    --color-blue4-70: rgba(77,196,248,1);
    --color-blue4-50: rgba(128,213,250,1);
    --color-blue4-20: rgba(204,238,253,1);
    --color-blue4-10: rgba(230,247,254,1);

    --color-blue-gradient: radial-gradient(59.68% 59.68% at 20.05% 20.14%, var(
    --color-blue0-100) 33.33%, var(--color-blue1-100)  100%);

    --color-turquoise-100: rgba(0,238,238,1);
    --color-accent-green-100: rgba(0,255,0,1);
    --color-accent-pink-100: rgba(255,0,255,1);

    --color-white-100: rgba(255,255,255,1);
    --color-grey-100: rgba(230,230,230,1);
    --color-quick-silver-100: rgba(163,163,163,1);
    --color-dark-silver-100: rgba(112,112,112,1);
    --color-dark-grey-100: rgba(57,57,57,1);
    --color-eerie-black-100: rgba(31,31,31,1);
    --color-nero-black-100: rgba(24,24,24,1);

    --color-status-success-100: rgba(25,128,56,1);
    --color-status-success-10: rgba(232,242,235,1);
    --color-status-error-100: rgba(218,30,40,1);
    --color-status-error-10: rgba(251,233,234,1);
    --color-status-warning-100: rgba(241,194,27,1);
    --color-status-warning-10: rgba(254,249,232,1);
    --color-status-information-100: rgba(0,67,206,1);
    --color-status-information-10: rgba(230,236,250,1);
    --color-status-off-100: var(
    --color-grey-100);
}

/* Reset */
* {
    margin: 0;
    padding: 0;
    box-sizing: border-box;
    z-index: inherit;
}

body {
    background-color: var(--color-white-100);
    color: var(--color-blue0-100);
    font-family: "Poppins", sans-serif;
}

a {
    text-decoration: none;
}

ul {
    list-style: none;
}
h1 {
    margin: 0 0 16px 0;
}
h2 {
    margin: 0 0 8px 0;
}
.hidden {
    display: none;
}

/* Header */
.header {
    background-color: var(--color-blue1-100);
    box-shadow: 1px 1px 5px 0px var(--color-grey-100);
    position: relative;
    top: 0;
    width: 100%;
}

/* Logo */
.logo {
    display: inline-block;
    color: var(---color-white-100);
    font-size: 40px;
    height: 40px;
    line-height: 40px;
    margin: 16px;

}

/* Nav menu */
.nav {  
    font-family: "Fedra Mono Demi";
    text-transform: lowercase;
    width: 100%;
    height: 100%;
    position: fixed;
    background-color: var(--color-blue0-100);
    overflow: hidden;
    max-height: 0;
    transition: max-height .5s ease-out;
    z-index: 100;
}

.menu a {
    display: block;
    line-height: 24px;
    margin: 20px 16px;
    padding: 4px 8px;
    color: var(--color-turquoise-100);
    transition: .2s ease-out;
}

.menu a:hover {
    background-color: var(--color-turquoise-100);
    color: var(--color-blue0-100);
}


/* Menu Icon */

.hamb {
    cursor: pointer;
    float: right;
    padding: 35px 24px;
}


.hamb-line {
    background: var(--color-white-100);
    display: block;
    height: 2px;
    position: relative;
    width: 24px;
    
}
.hamb-line::before,
.hamb-line::after {
    background: var(--color-white-100);
    content: '';
    display: block;
    height: 100%;
    position: absolute;
    transition: all .2s ease-out;
    width: 100%;
}
.hamb-line::before {
    top: 8px;
}
.hamb-line::after {
    top: -8px;
}


.side-menu {
    display: none;
}

/* Toggle menu icon */

.side-menu:checked ~ nav{
    max-height: 100%;
}

.side-menu:checked ~ .hamb .hamb-line {
    background: transparent;
}

.side-menu:checked ~ .hamb .hamb-line::before {
    transform: rotate(-45deg);
    top:0;

}

.side-menu:checked ~ .hamb .hamb-line::after {
    transform: rotate(45deg);
    top:0;
}

main {
    padding: 16px;
}


.camera-grid {
    max-width: 1200px;
    margin: 0 auto;
    display: grid;
    gap: 1rem;
}
.camera-grid .joystick {
    justify-self: center;
    z-index: 99;
}
.camera-grid .stream-container {
    max-width: 100%;
}
@media (min-width: 480px) {
    .camera-grid { 
        grid-template-columns: 1fr 256px; 
    }
    .camera-grid .joystick {
        align-self: end; */
        justify-self: left;
    }
  }


/* Responsiveness */

@media (min-width: 768px) {
    .nav {
        max-height: none;
        top: 0;
        position: relative;
        float: right;
        width: fit-content;
        background-color: transparent;

    }
    .menu li{
        float: left;
    }
    .menu a:hover {
    }
    
    .hamb{
        display: none;
    }

}    
)V0G0N";