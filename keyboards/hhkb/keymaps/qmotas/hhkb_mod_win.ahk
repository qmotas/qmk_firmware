; 無変換/変換はUSキーボードだと認識されないため割り当て直す
sc07B::Send, {vk1Dsc07B}
sc079::Send, {vk1Csc079}

;; Windows固有の設定
; エクスプローラのカラム幅自動調整をCtrl + =でやる
^=::Send, ^{NumpadAdd}

; 上部メニューがアクティブになるのを抑制
*~LAlt::Send {Blind}{vk07}
*~RAlt::Send {Blind}{vk07}

;; アプリ用設定
; SwitcherooのホットキーにCtrl + `が使えないので、Ctrl + Alt + `にマッピングしてこれを使う
^SC029::Send, ^!{``}