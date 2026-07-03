# start-ssh-agent.ps1
# Starts the ssh-agent service (if not running) and adds your key.
# Note: first-time service enablement still needs an admin terminal.

$keyPath = "$env:USERPROFILE\.ssh\id_ed25519"

$service = Get-Service ssh-agent -ErrorAction SilentlyContinue

if (-not $service) {
    Write-Host "ssh-agent service not found. Is OpenSSH Client installed?"
    exit 1
}

if ($service.Status -ne 'Running') {
    Write-Host "Starting ssh-agent service..."
    try {
        Start-Service ssh-agent
    }
    catch {
        Write-Host "Failed to start ssh-agent. Try running this script as Administrator once to enable it."
        exit 1
    }
}
else {
    Write-Host "ssh-agent is already running."
}

if (-not (Test-Path $keyPath)) {
    Write-Host "Key not found at $keyPath — update `$keyPath in the script."
    exit 1
}

Write-Host "Adding key: $keyPath"
ssh-add $keyPath

Write-Host "`nLoaded keys:"
ssh-add -l