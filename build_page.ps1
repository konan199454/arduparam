# Перетворює web\index.html на ArduParam\page.h (запускати після змін у сторінці)
$root = $PSScriptRoot
$html = [IO.File]::ReadAllText("$root\web\index.html", [Text.Encoding]::UTF8)
if ($html.Contains(')PAGE_RAW')) { throw 'index.html contains the raw-string terminator' }
$out = "#pragma once`n// Згенеровано з web/index.html скриптом build_page.ps1. Не редагуйте вручну.`nconst char PAGE[] PROGMEM = R`"PAGE_RAW(" + $html + ")PAGE_RAW`";`n"
[IO.File]::WriteAllText("$root\ArduParam\page.h", $out, (New-Object Text.UTF8Encoding $false))
Write-Output ("page.h: {0:N0} bytes" -f (Get-Item "$root\ArduParam\page.h").Length)
