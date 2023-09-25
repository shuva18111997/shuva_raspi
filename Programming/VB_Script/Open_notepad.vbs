Set WshShell = WScript.CreateObject("WScript.Shell")
WshShell.Run "notepad", 9
WScript.Sleep 500 ' Give Notepad some time to load
For i = 1 To 100
  WshShell.SendKeys "Hello World!"
  WshShell.SendKeys "{ENTER}"
Next