# 🪐 42 | Simulateur de compte bancaire
~ 13 / 03 / 2025 ~

---

## 🌿 -- FR --

> 📌 • **Fonctionnalités intégrées** :
- Création de profil (Nom, Prénom, Code pin, Solde)
- Chiffrement du code pin
- Modification du solde : ajout / retrait
- Consultation du solde
- Suppression du profil



> 🏗️ • **Difficultés rencontrées** :
- Mon objectif principal était de faire avec une intégration de base de données, cependant j'ai rencontré beaucoup de difficultés sur l'ajout de libraries mysql et lib config pour l'utilisation de fichier `.config` pour une gestion sécurisé de la connexion à la DB (qui n'a pas abouti).
  - Je suis donc partie sur une gestion locale par le biais de dossier au format `Nom_Prénom`.
- De plus, je voulais chiffrer les code pin avec un hash, cependant, même problème, il fallait ajouter des librairies, je suis donc partie sur un chiffrage simple mais peu sécurisé.

---

## 🌎 -- EN --

> 📌 • **Integrated Features**:
- Profile creation (First Name, Last Name, PIN Code, Balance)
- PIN code encryption
- Balance modification: deposit/withdrawal
- Balance consultation
- Profile deletion

> 🏗️ • **Challenges Encountered**:
- My main goal was to integrate a database; however, I faced many difficulties in adding MySQL libraries and using `.config` file for secure DB connection management (which was unsuccessful).
    - As a result, I opted for local management using folders named `FirstName_LastName`.
- Additionally, I wanted to hash PIN codes, but again, I encountered issues with library installation. So, I used a simple but less secure encryption method.

---

*🪐 42, like the only answer in the universe ✨*

---