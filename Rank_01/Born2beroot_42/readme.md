# 🚀 Project Name: Born2beRoot

## 🖥️ Project Overview:
Born2beRoot introduces you to system administration and server setup. Your mission is to build a secure server efficiently, with minimal services and complied to strict rules! 🌐

## 🔒 Services and Rules:
Operating System: Choose either Debian or Rocky, both secured with SELinux (and AppArmor for Debian)
Data Protection: Create two encrypted partitions using LVM to safeguard your data
SSH Security: SSH operates on port 4242, with root login disabled
Firewall Rules: Implement UFW (or firewalld for Rocky) and allow only port 4242.
User Management: Set a unique hostname, enforce strong password policies, and create a sudo user for enhanced security.
