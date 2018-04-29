-- phpMyAdmin SQL Dump
-- version 4.7.4
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1
-- Généré le :  Dim 29 avr. 2018 à 23:20
-- Version du serveur :  10.1.28-MariaDB
-- Version de PHP :  7.1.11

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `pfa_cpp`
--

-- --------------------------------------------------------

--
-- Structure de la table `buying_contract`
--

CREATE TABLE `buying_contract` (
  `id` int(11) NOT NULL,
  `id_logement` int(11) NOT NULL,
  `id_client` int(11) NOT NULL,
  `status` int(11) NOT NULL,
  `value` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `buying_contract`
--

INSERT INTO `buying_contract` (`id`, `id_logement`, `id_client`, `status`, `value`) VALUES
(1, 2, 1, 0, 100),
(2, 0, 5, 0, 20);

-- --------------------------------------------------------

--
-- Structure de la table `client`
--

CREATE TABLE `client` (
  `id` int(11) NOT NULL,
  `name` text NOT NULL,
  `surname` text NOT NULL,
  `date_of_birth` text NOT NULL,
  `password` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `client`
--

INSERT INTO `client` (`id`, `name`, `surname`, `date_of_birth`, `password`) VALUES
(1, 'sdfsfdsf', 'dfsdfsdf', 'sdfsdsdf', 'sdfsdf');

-- --------------------------------------------------------

--
-- Structure de la table `employee`
--

CREATE TABLE `employee` (
  `id` int(11) NOT NULL,
  `name` varchar(40) NOT NULL,
  `surname` varchar(40) NOT NULL,
  `date_of_birth` varchar(40) NOT NULL,
  `poste` text NOT NULL,
  `salaire` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `employee`
--

INSERT INTO `employee` (`id`, `name`, `surname`, `date_of_birth`, `poste`, `salaire`) VALUES
(1, 'goood', 'goodmorning', '11-20-20', 'directeur', 120.6),
(4, 'sdf', 'dhgf', 'sdg', 'dgdfg', 10),
(5, 'sdf', 'dhgf', 'sdg', 'dgdfg', 10),
(6, 'heni', 'ounu', '10-9-1996', 'najjar', 20),
(7, 'lassad', 'kefi', '10051995', 'dev', 2555560);

-- --------------------------------------------------------

--
-- Structure de la table `logement`
--

CREATE TABLE `logement` (
  `id` int(11) NOT NULL,
  `id_prop` int(11) NOT NULL,
  `title` text NOT NULL,
  `description` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `logement`
--

INSERT INTO `logement` (`id`, `id_prop`, `title`, `description`) VALUES
(9, 1, 'heni', 'bonjour'),
(10, 0, 'heni', 'ouni'),
(11, 8526920, 'heni', 'bonjour'),
(12, 1, 'aaslema', 'haya');

-- --------------------------------------------------------

--
-- Structure de la table `problem`
--

CREATE TABLE `problem` (
  `id` int(11) NOT NULL,
  `id_reporter` int(11) NOT NULL,
  `id_logement` int(11) NOT NULL,
  `title` text NOT NULL,
  `description` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `problem`
--

INSERT INTO `problem` (`id`, `id_reporter`, `id_logement`, `title`, `description`) VALUES
(11, 1, 2, 'blq b', 'blq');

-- --------------------------------------------------------

--
-- Structure de la table `proprietaire`
--

CREATE TABLE `proprietaire` (
  `id` int(11) NOT NULL,
  `name` text NOT NULL,
  `surname` text NOT NULL,
  `password` text NOT NULL,
  `date_of_birth` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `proprietaire`
--

INSERT INTO `proprietaire` (`id`, `name`, `surname`, `password`, `date_of_birth`) VALUES
(1, 'lassad', 'jfgj', 'ghk', 'fgjf'),
(2, 'heni', 'ounu', 'heni', '10-20-2010'),
(3, 'good ', 'morning', 'dull', '20-11-2016');

-- --------------------------------------------------------

--
-- Structure de la table `renting_contract`
--

CREATE TABLE `renting_contract` (
  `id` int(11) NOT NULL,
  `id_logement` int(11) NOT NULL,
  `id_client` int(11) NOT NULL,
  `status` int(11) NOT NULL,
  `end_date` text NOT NULL,
  `start_date` text NOT NULL,
  `amount_per_month` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `renting_contract`
--

INSERT INTO `renting_contract` (`id`, `id_logement`, `id_client`, `status`, `end_date`, `start_date`, `amount_per_month`) VALUES
(1, 1, 1, 1, 'tgeryhg', 'terfgh', 101),
(2, 0, 3, 0, '10-20-30', '30-1-2005', 30);

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `buying_contract`
--
ALTER TABLE `buying_contract`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `client`
--
ALTER TABLE `client`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `employee`
--
ALTER TABLE `employee`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `logement`
--
ALTER TABLE `logement`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `problem`
--
ALTER TABLE `problem`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `proprietaire`
--
ALTER TABLE `proprietaire`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `renting_contract`
--
ALTER TABLE `renting_contract`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `buying_contract`
--
ALTER TABLE `buying_contract`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT pour la table `client`
--
ALTER TABLE `client`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT pour la table `employee`
--
ALTER TABLE `employee`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- AUTO_INCREMENT pour la table `logement`
--
ALTER TABLE `logement`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=13;

--
-- AUTO_INCREMENT pour la table `problem`
--
ALTER TABLE `problem`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;

--
-- AUTO_INCREMENT pour la table `proprietaire`
--
ALTER TABLE `proprietaire`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT pour la table `renting_contract`
--
ALTER TABLE `renting_contract`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
