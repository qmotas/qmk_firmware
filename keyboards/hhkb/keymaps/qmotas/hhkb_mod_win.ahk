; 無変換/変換はUSキーボードだと認識されないため割り当て直す
sc07B::Send, {vk1Dsc07B}
sc079::Send, {vk1Csc079}

; タスクビューの操作をOSXに寄せる
^Up::Send, #{Tab}
^Left::Send, #^{Left}
^Right::Send, #^{Right}

;; Windows固有の設定
; エクスプローラのカラム幅自動調整をCtrl + =でやる
^=::Send, ^{NumpadAdd}

; 上部メニューがアクティブになるのを抑制
*~LAlt::Send {Blind}{vk07}
*~RAlt::Send {Blind}{vk07}
