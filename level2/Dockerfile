# Utiliser une image de base Ubuntu pour l'architecture amd64
FROM --platform=linux/amd64 ubuntu:22.04

# Installer les dépendances nécessaires pour exécuter des binaires 32 bits
RUN dpkg --add-architecture i386 && \
    apt-get update && \
    apt-get install -y \
    libc6:i386 \
    libncurses5:i386 \
    libstdc++6:i386 \
    gdb \
    strace \
    ltrace \
    binutils \
    elfutils \
    git \
    build-essential \
    cmake \
    file \
    python3


# Copier le fichier binaire dans l'image Docker
COPY level2 /level2

# Donner les permissions d'exécution au fichier binaire
RUN chmod +x /level2

# Définir le point d'entrée
CMD ["/bin/bash"]
