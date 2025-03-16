# Cara Kerja Kode Lengan

Kode menggunakan transformasi hierarkis dengan `glPushMatrix()` dan `glPopMatrix()` untuk mengisolasi transformasi tiap bagian lengan.

## Shoulder
Diputar menggunakan `glRotatef` dengan sumbu z. Translasi dilakukan untuk memposisikan lengan atas.

## Elbow
Setelah lengan atas, translasi dan rotasi diterapkan untuk lengan bawah.

## Kontrol
Tombol keyboard `s/S` dan `e/E` mengubah sudut shoulder dan elbow, lalu `glutPostRedisplay()` dipanggil untuk memperbarui tampilan.
