Block blocks[] = {
    // Current time, updates every second
    { "", "date '+%H:%M:%S'", 1, 0 },
    // Audio volume with 'vol' label, updates every second
    { "", "echo -n 'vol '; amixer get Master | grep -o '[0-9]*%' | head -n 1", 1, 0 },
    // CPU temperature (in °C), updates every second
    { "", "awk '{sum+=$1} END {printf \"%.0f°C\\n\", sum/NR/1000}' /sys/class/thermal/thermal_zone*/temp", 1, 0 },
    // Online/offline status, updates every 10 seconds
    { "", "ping -c1 -W1 8.8.8.8 >/dev/null 2>&1 && echo 'Online' || echo 'Offline'", 10, 0 },
};
