<?php
include ('connect.php');
mysql_select_db('dbtromaninNewWorld',$maBase); 

$req1="select * from utilisateur";
$result=mysql_query($req1);
while($tab=mysql_fetch_row($result))
{
     $no=$tab[0];
     $nom=$tab[1];
     $to=$tab[8];
     $subject = 'Votre catalogue New World!';
     $message = 'Votre catalogue : ';
     $message.= 'http://172.16.63.111/NW/catalogue_'.$nom.$no.'.pdf';
     $headers = 'From: catalogue@newWorld.com' . "\r\n" .
     'Reply-To: catalogue@newWorld.com' . "\r\n" .
     'X-Mailer: PHP/' . phpversion();

     mail($to, $subject, $message, $headers);
}
?>
