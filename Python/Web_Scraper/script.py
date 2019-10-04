"""Test script.

This script shows how to use firefox webdriver
"""
from datetime import date, timedelta
from typing import List
from customarticleswebscraper import CustomArticlesWebScraper
from article import Article
from htmlarticlesexporter import HtmlArticlesExporter

print("Start web scraper")

# Set a date reference
dateReference = date.today()-timedelta(days=3650)

# Init articles list
articles: List[Article] = []

# Get data from a specific source
customArticlesWebScraper: CustomArticlesWebScraper = CustomArticlesWebScraper()
customArticlesWebScraper.execute(dateReference)
articles += customArticlesWebScraper.getArticles()

# [...]
# You can concatenate another articles here
# [...]

# Remove duplicate entries and sort articles by most recent
articles = list(set(articles))
articles.sort(key=lambda x: x.getDate(), reverse=True)

# Export articles list in html
exporter: HtmlArticlesExporter = HtmlArticlesExporter(articles)
exporter.export()

print("End web scraper")
