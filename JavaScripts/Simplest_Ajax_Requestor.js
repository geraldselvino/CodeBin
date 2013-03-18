/**********************************************
* Author: Gerald Selvino
* Description: A very simple implementation of Ajax
* Language: JavaScript
***********************************************/

/**
 * returns an object of XMLHttpRequest
 *
 * XMLHttpRequest is the object that sends request to the server
 *
 * @return object of XMLHttpRequest or null
 */
function getHTTPObject()
{
    if (window.ActiveXObject){
        return new ActiveXObject("Microsoft.XMLHTTP");
    }
    else if (window.XMLHttpRequest){
        return new XMLHttpRequest();
    }
    else {
        alert("Your browser does not support AJAX.");
        return null;
    }
}

/**
 * Sends request to the server, the main ajax function
 *
 * Will request for the page contained in the first parameter,
 * then put the resulting output inside the HTML element with
 * ID = the second parameter.
 *
 * @param param              The page to request to the web server
 * @param elementid          The ID of the HTML element where the 
 *                           result will be placed.
 * @param httpObjectParam    If you want to create the XMLHttpRequest
 *                           outside, you pass it here.
 */
function doAjaxWay(param,elementid,httpObjectParam)
{
    var httpObject;

    if (httpObjectParam == null){
        httpObject = getHTTPObject();
    }
    else{
        httpObject = httpObjectParam;
    }
    
    if (httpObject != null){
        if (httpObject.readyState == 4 || httpObject.readyState == 0){
            httpObject.open("GET", param, true);
            httpObject.onreadystatechange = function(){
                if(httpObject.readyState == 4){
                    if (httpObject.status == 200){
                        var ajaxDisplay = document.getElementById(elementid);    
                        // Use RegEx to strip any <script> contents
                        var myregexp = new RegExp("(?:<script[^>]*>)([a-zA-Z\s\w\d\n\t\r\f\0\.,/_\(\)\"0-9]+[^</]*?)(?:</script[^>]*>)", "im");
                        var match = myregexp.exec(httpObject.responseText);
                                            
                        if (match != null){
                            alert("A script is detected from the content, Script is not allowed in the AJAX content, \n Please modify it.");
                        }
                        else{
                            ajaxDisplay.innerHTML = httpObject.responseText;
                        }        
                    }
                }
            }
            httpObject.send(null);
        }
        else{
            // if the connection is busy, try again after one second
            setTimeout('doAjaxWay(param,elementid,httpObject)', 1000);
        }
    }
}
