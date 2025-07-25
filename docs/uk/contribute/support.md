# Підтримка

<script setup>
import { useData } from 'vitepress'
const { site } = useData();
</script>

<div v-if="site.title !== 'PX4 Guide (main)'">
  <div class="custom-block danger">
    <p class="custom-block-title">Ця сторінка може бути застарілою. <a href="https://docs.px4.io/main/en/contribute/support.html">Переглянути останню версію</a>.</p>
  </div>
</div>

Цей розділ показує, як ви можете отримати допомогу від основної команди розробників і широкої спільноти.

## Форум та чат

Основна команда розробників і спільнота активні на наступних каналах:

- [PX4 Discuss Forum](https://discuss.px4.io/) - Post here first!
- [PX4 Discord](https://discord.gg/dronecode) - Post here if you don't get a response in discuss within a few days (include a link to your forum topic).

:::tip
The Discuss Forum is much preferred because it is indexed by search engines and serves as a common knowledge base.
:::

## Діагностування проблем

Якщо ви не впевнені в тому, що є ця проблема, і вам потрібна допомога для діагностики

- Upload logs to [Flight Log Review](https://logs.px4.io/)
- Open a discussion on [PX4 Discuss](https://discuss.px4.io/c/flight-testing/10) with a flight report and links to logs.
- The dev team may prompt you to [raise an issue](#issue-bug-reporting) if the problem is caused by a bug.

## Issue & Bug Reporting

- Upload logs to [Flight Log Review](https://logs.px4.io/)
- [Open a Github Issue](https://github.com/PX4/PX4-Autopilot/issues).
  Включити звіт про польоти з якомога більшою кількістю деталей (достатньо для того, щоб проблема була відтворена) і посилання на ваші журнали на Flight review.

## Щотижневий дзвінок розробників

:::tip
Developers are most welcome to attend the [weekly dev call](../contribute/dev_call.md) (and other [developer events](../index.md#calendar-events)) to engage more deeply with the project.
:::

The [Dev Call](../contribute/dev_call.md) is a weekly meeting attended by the PX4 dev team to discuss platform technical details, coordinate activities and perform in-depth analysis.

There is also space in the agenda to discuss pull requests, major impacting issues and Q&A.
