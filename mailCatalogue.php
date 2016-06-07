<?php
include ('connect.php');

$req="select usId, usEmail from Utilisateur";
$result=mysqli_query($maBase,$req);

$today=date("d-m-Y");//pour le nom du ficher

while($tab=mysqli_fetch_array($result))
{
    $id=$tab['usId'];
    $reqPointVente="select pvId from PointVente inner join QuiAcheteOu on idPointVente=pvId where idUtilisateur=$id";
    $resultPV=mysqli_query($maBase,$reqPointVente);
    $chaineDePV="";
    while($lignePV=mysqli_fetch_array($resultPV))
    {
        $chaineDePV.="_".$lignePV['pvId'];
        //echo $lignePV['pvId'].'_';
    }
    
    if($chaineDePV!="")//si l'utilsateur à des pts de vente
    {
        $chaine=$today.$chaineDePV;

         $to=$tab['usEmail'];
         $subject = 'Votre catalogue New World!';
         $message = 'Votre catalogue : ';
         $message.= 'http://172.16.63.111/NW/catalogueNW_'.$chaine.'.pdf';
         $headers = 'From: catalogue@newWorld.com' . "\r\n" .
         'Reply-To: catalogue@newWorld.com' . "\r\n" .
         'X-Mailer: PHP/' . phpversion();
    
         mail($to, $subject, $message, $headers);
    }
}
?>
