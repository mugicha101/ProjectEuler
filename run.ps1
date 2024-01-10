param([bool]$recompile=$true)
if ($recompile) {
    if (Test-Path -Path './a.exe') {
        Remove-Item ./a.exe
    }
    if (Test-Path -Path './main.txt') {
        Remove-Item ./main.txt
    }
    g++ -O3 -fpermissive ./main.cpp
}
if (Test-Path -Path './output.txt') {
    Remove-Item ./output.txt
}
if (Test-Path -Path './a.exe') {
    ./a.exe | Tee-Object ./output.txt
    Copy-Item ./main.cpp ./main.txt
    $line = 0
    (Get-Content ./main.txt | Foreach-Object {
        if ($line++ -eq 3) { 
            $_ -replace 'true','false' 
        } else { $_ } 
    }) | Set-Content ./main.txt
}