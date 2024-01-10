param([string]$name)
if (Test-Path -Path "./solutions/$name.cpp") {
    write-output "solution already exists, operation cancelled."
} else {
    Copy-Item ./main.cpp ./solutions/$name.cpp
}