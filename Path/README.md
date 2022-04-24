## Powershell script
```ps1
$FilePath = "..."

if ($args.count -eq 0) {
    Start-Process $FilePath
}
else {
    Start-Process $FilePath $args
}
```

## Command prompt script
```bat
@echo off
powershell script_name.ps1 %*
```