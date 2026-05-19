
<!DOCTYPE html><html><head><meta charset="UTF-8">
<title>Dashboard Études</title>
<style>
body{font-family:Arial;background:linear-gradient(135deg,#0f172a,#111827);color:white;padding:30px}
.section{margin-bottom:40px}
.title{font-size:30px;border-bottom:1px solid #555;padding-bottom:8px;margin-bottom:20px}
.grid{display:grid;grid-template-columns:repeat(auto-fit,minmax(280px,1fr));gap:20px}
.card{background:rgba(255,255,255,.08);padding:20px;border-radius:22px}
.big{font-size:34px;font-weight:bold}
</style></head><body>
<h1>Dashboard Études</h1>

<div class=section>
<div class=title>Vue globale</div>
<div class=grid>
<div class=card><h3>Fin du diplôme</h3><div id=diploma class=big></div></div>
<div class=card><h3>Semaines de cours restantes</h3><div id=weeks class=big></div></div>
</div></div>

<div class=section>
<div class=title>Fin des cours par année</div>
<div class=grid>
<div class=card><h3>3A</h3><div id=c1 class=big></div></div>
<div class=card><h3>4A</h3><div id=c2 class=big></div></div>
<div class=card><h3>5A</h3><div id=c3 class=big></div></div>
</div></div>

<script>
const diploma=new Date("2028-09-30T23:59:59");
const totalSchoolWeeks=45;
const schoolPeriods=[["2026-06-01","2026-07-10"],["2026-09-01","2026-12-31"],["2027-01-01","2027-04-30"],["2027-09-01","2028-05-05"]];
const dates=[["c1",new Date("2026-07-10")],["c2",new Date("2027-04-30")],["c3",new Date("2028-05-05")]];

function fmt(d){
let diff=d-new Date();
if(diff<=0)return "Terminé ✅";
let days=Math.floor(diff/86400000);
return days+" jours<br>"+(days/7).toFixed(1)+" semaines";
}
function remainingSchool(){
let now=new Date();
let consumed=0;
schoolPeriods.forEach(p=>{
let s=new Date(p[0]);
let e=new Date(p[1]);
if(now>s){
let lim=now<e?now:e;
consumed+=Math.max(0,(lim-s)/86400000/7);
}});
return Math.max(0,totalSchoolWeeks-consumed).toFixed(1);
}
function upd(){
document.getElementById("diploma").innerHTML=fmt(diploma);
document.getElementById("weeks").innerHTML=remainingSchool()+" semaines";
dates.forEach(d=>document.getElementById(d[0]).innerHTML=fmt(d[1]));
}
upd();setInterval(upd,1000);
</script></body></html>
