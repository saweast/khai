function convertToStringD (param1) {
	switch (param1) {
		case '0': return inputMoney = 'USD'; 
			break;
		case '1': return inputMoney = 'Eur'; 
			break;
		case '2': return inputMoney = 'Ruble';
			break;
		case '3': return inputMoney = 'Hryvnia';
			break;
		case '4': return inputMoney = 'Polish Zloty';
			break;
		default: return inputMoney = 'unknown currency';
	}
}
function convertToStringT (param2) {
	switch (param2) {
		case '0': return outputMoney = 'USD'; 
			break;
		case '1': return outputMoney = 'Eur'; 
			break;
		case '2': return outputMoney = 'Ruble';
			break;
		case '3': return outputMoney = 'Hryvnia';
			break;
		case '4': return outputMoney = 'Polish Zloty';
			break;
		default: return outputMoney = 'unknown currency';
	}
}



document.getElementById("check").addEventListener("click", function(){
	makeResult(inputMoney, inputValue, outputMoney, outputValue, disValue);
}, false)

function makeResult (im, iv, om, ov, dv) {

	Window = window.open("", "MsgWindow", "width=500, height=300");	
	Window.document.write('From: ' + iv + ' ' +im + "\n" + 
			'To: ' + ov + ' ' + om + "\n" +
			'Discount: ' + dv);	
	Window.document.write("<script>setTimeout(function(){window.close();}, 10000);</script>");	
}
function makeHist (im, iv, om, ov, dv) {
	if (iv >= 1000) {
		text = "<p class='special'><b>"+im+"</b>"+" "+iv+" is <b>"+om+"</b>"+" "+ov+" (Discount: "+dv+")</p>";
	}
	else text = "<p><b>"+im+"</b>"+" "+iv+" is <b>"+om+"</b>"+" "+ov+" (Discount: "+dv+")</p>";
	 
	hist = document.getElementsByClassName('history')[0];
	hist.innerHTML += text;
	text = "";
}

	var	c = new Array();
	var	n = new Array();
		c[0] = 1;
		n[0] = "USD";
		c[1] = 0.75;
		n[1] = "EUR";
		c[2] = 29.89;
		n[2] = "RUB";
		c[3] = 7.97;
		n[3] = "UAH";
		c[4] = 3.05;
		n[4] = "PLN";
		
		
 
 	function CheckFields(){
		 if(document.Form1.from.value==document.Form1.to.value) document.Form1.Calculate.disabled=true;
		 else document.Form1.Calculate.disabled=false;
		}
 
 function Convert(vFrom, vTo, vCash)
 {
 return c[vTo] * vCash / c[vFrom];
 }
     function Conv()
		{
			var res, vfrom, vto, vcash,discont;
			vcash = document.getElementById("cash").value;
			vfrom = document.getElementById("from").value;
			vcash = vcash.replace(',', '.');
			vcash = vcash.replace(' ', '');
			vcash = vcash.replace(' ', '');
			vto = document.getElementById("to").value;
			res=Convert(vfrom, vto, vcash);
			if (vcash>100) {
			discont=10*res/100;
			res-=discont;
			}
			else {discont=0;}
		if(isNaN(res))
		{
			res = "<span class='result'>0,00</span>";
			
		}
		else
		{
		
			res = res.toFixed(2);
			res = res.toString();
			res = res.replace('.', ',');
			res = "<span class='result'>" + res + "</span>&nbsp;" + n[vto];
			
			discont = discont.toFixed(2);
			discont = discont.toString();
			discont = discont.replace('.', ',');
			discont = "<span class='discont'>" + discont + "</span>&nbsp;"+ n[vto]
		}
		document.getElementById("result").innerHTML = res;
		document.getElementById("discont").innerHTML = discont;
		
		outputValue = document.getElementsByClassName('result')[0].textContent;
		disValue = document.getElementsByClassName('discont')[0].textContent;
		inputMoney = document.getElementById('from');
		inputMoney = inputMoney.value;
		inputValue = document.getElementById('cash');
		inputValue = inputValue.value;
		outputMoney = document.getElementById('to');
		outputMoney = outputMoney.value;
		convertToStringD(inputMoney);
		convertToStringT(outputMoney);
		makeHist(inputMoney, inputValue, outputMoney, outputValue, disValue);
		return outputValue, disValue, inputMoney, inputValue, outputMoney;
		}
		
	function GetCourse()
	{
	  var val = document.FormCourse.Course.value;
	  document.FormCourse.CourseValue.value=c[val];
	}
	
	function SetCourse()
	{
	  var val = document.FormCourse.Course.value;
	  c[val]=document.FormCourse.CourseValue.value;
	}
	function CheckEmptyValue()
	{
	
	  if (document.FormCourse.CourseValue.value.length==0 ||  isNaN(document.FormCourse.CourseValue.value) || document.FormCourse.CourseValue.value==0)
	  {
	  document.FormCourse.SaveCourse.disabled=true;
	 }
	 else {
	 document.FormCourse.SaveCourse.disabled=false;
	 }
	}

