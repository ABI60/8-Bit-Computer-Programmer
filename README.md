# 8-Bit Computer Programmer
Sıfırdan yaptığım 8-bit bilgisayarın devre içi programlayıcısı ve debugger ı.

- Programlayıcı C ile ve MPLAB kullanılarak yazılmıştır, PIC18F1826 mikrodenetleyicisini kullanır.

- USB-UART üzerinden konuşur ancak UART prokolü üzerine ekstra kendi prokolümü kurdum. Bu protokolde paketler 4byte lıktır ve 1byte ı checksum olarak kullanılır, ayrıca programlayıcı her veri alımından sonra ACK sinyali gönderir. Bu şekilde yanlış sinyal hatası veya yanlış veri gönderme gibi bir durum olmaz.

- Programlayıcı otomatik olarak bağlantı kesildiğini anlar ve tamamen kendi içinde bir sistemdir. Sanki bir modülmüş gibi, gerekli zamanda gerekli protokol verilerini göndererek çalıştırılır.

- Programlayıcı ayrı ayrı mosfetler ile ve sadece sinyalleri toprağa çekerek çalışır, böylece çiplerdeki ESD korumaları yüzünden sinyallerinden bilgisayara güç vermez ve almaz, böylece ikisi birbirinden izole kalır ve biri kapalıyken diğerine bağlanabilir.

- Programlama devre içi kullanılır yani EEPROM ları çıkarıp programlayıp yeniden koyma gibi bir durum olmaz. Programlayıcı saati stoplama sinyaline bağlı, yani sistemi durdurup direkt devreye bağlı olarak EEPROM ları programlayabilir.

- Programlayıcı durdurma, saat, reset ve bunların yanında program adres ve opcode sinyallerine direkt erişimi var, bunun sayesinde IDE içine debug sistemi ekleyerek gerçek bir IDE ye dönüştürme mümkün.(ileride test etmeyi büyük ölçüde kolaylaştıracaktır)


<img src="./Resimler/MPLAB Resim.jpg" width="500">

# Programlayıcı resimleri:
<p float="left">
  <img src="./Resimler/Üst Resim.png" width="200">
  <img src="./Resimler/Alt Resim.png" width="200">
</p>
<p float="left">
  <img src="./Resimler/Çalışır Resim-1.png" width="200">
  <img src="./Resimler/Çalışır Resim-2.png" width="200">
</p>
<p float="left">
  <img src="./Resimler/Ön Resim.png" width="200">
  <img src="./Resimler/Arka Resim.png" width="200">
</p>
<p float="left">
  <img src="./Resimler/İç Resim-1.png" width="200">
  <img src="./Resimler/İç Resim-2.png" width="200">
</p>

# Devre Resmi:
<p float="left">
  <img src="./Resimler/Devre Ön Resim.png" width="200">
  <img src="./Resimler/Devre Arka Resim.png" width="200">
</p>

# Devre Şeması:
<p float="left">
  <img src="./Resimler/Programlayıcı Bağlantı Şema.png" width="300">
  <img src="./Resimler/Programlayıcı Devre Şema.png" width="400">
  <img src="./Resimler/Plaket Devre Şema.png" width="300">
</p>
