/**********************************************
* Author: Gerald Selvino
* Description: Calculates the difference of 2
*              dates just like how a human would
*              do it.
* Language: JavaScript
***********************************************/
function dateDiff(y1, m1, d1, y2, m2, d2){
    var SY, SM, SD;
    var EY, EM, ED;
    var Year; //Year difference is stored in this variable
    var Month; //Month difference is stored in this variable
    var Day; //Day difference is stored in this variable
    
    if(y1<y2){
        SY = y1; SM = m1; SD = d1;
        EY = y2; EM = m2; ED = d2;
    }
    else if(y1>y2){
        SY = y2; SM = m2; SD = d2;
        EY = y1; EM = m1; ED = d1;
    }
    else if(y1==y2){
        if(m1<m2){
            SY = y1; SM = m1; SD = d1;
            EY = y2; EM = m2; ED = d2;            
        }
        else if(m1>m2){
            SY = y2; SM = m2; SD = d2;
            EY = y1; EM = m1; ED = d1;
        }
        else if(m1==m2){
            if(d1<d2){
                SY = y1; SM = m1; SD = d1;
                EY = y2; EM = m2; ED = d2;        
            }
            else if(d1>d2){
                SY = y2; SM = m2; SD = d2;
                EY = y1; EM = m1; ED = d1;
            }
            else if(d1==d2){
                SY = y1; SM = m1; SD = d1;
                EY = y2; EM = m2; ED = d2;
            }
        }
    }
    
    var MonthNoDays = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    
    if(EM Mod 4 == 0) MonthNoDays[2] = 29;
    
    Year = Math.abs(EY - SY);

    var mDiff1 = MonthNoDays[EM-1] + ED - SD;
    var mDiff2 = mDiff1 - MonthNoDays[EM-1];
    
    if(Year==0){
        Month = Math.abs(EM-SM);
    }
    else if(Year>0){
        Month = 12 - (Math.abs(EM-SM));
    }
    
    if(mDiff2>0){
        Day = mDiff2;
    }
    else if(mDiff2<0){
        Day = mDiff;
        Month--;
    }
    
    Year--;
    
    /* The difference is stored in Year, Month, Day variable*/
}