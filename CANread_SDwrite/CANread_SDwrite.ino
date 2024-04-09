#include <SPI.h>
#include <SD.h>

File dataFile;

void setup() {
  // SDカードの初期化
  if (!SD.begin(5)) {  // CSピンは必要に応じて変更してください
    Serial.println("SDカードの初期化に失敗しました！");
    return;
  }
  Serial.println("SDカードが初期化されました。");

  // データファイルのオープン（新規作成）
  dataFile = SD.open("data.txt", FILE_WRITE);
  if (!dataFile) {
    Serial.println("ファイルを開けませんでした！");
    return;
  }

  // データの書き込み
  dataFile.println("Hello, SDカード!");
  dataFile.close();
}

void loop() {
  // 何もしない
}
